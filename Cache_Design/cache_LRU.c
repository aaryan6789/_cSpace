/* cache_LRU.c * Created on: Apr 29, 2018 * Author: Harsh */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

/*
 * LRU Cache is implemented using the following Data Structures:
 * 1. Queue - Doubly Linked List queue : Queue is a FIFO Structure
 * 	  QueueSize = Cache Size (Number of pages possible in a cache)
 * 	  Least Recently Used pages will be in the rear end of the queue.
 * 	  Since Queue is a FIFO structure so whenever a page is referenced it will be
 * 	  inserted in the front of the queue.
 *
 * 2. Hash Table - To keep track of a page. (Key:Value) ~ (pageNumber: Address of page QNode)
 *	  page number as key and address of the corresponding queue node as value.
 *	  pageNumber is the index of the Hash Table array.
 *
 * Eviction Policy: LRU Least Recently Used
 * The LRU caching scheme is to remove the least recently used frame when the cache is full and
 * a new page is referenced which is not there in cache.
 */

// Structure to represent a Queue Node
struct Qnode{
	unsigned int data;
	struct Qnode* next;
	struct Qnode* prev;
};

// Structure to represent the whole Queue
struct Queue{
	struct Qnode* front;
	struct Qnode* rear;
	unsigned int totalFrames;		// Total Frames allowed in the Cache
	unsigned int filledFrames;		// number of frames filled/ present in the Cache
};

// Structure to keep a map of entries in the Cache for Hit or Miss
// It will keep all the Nodes in the LRU cache as the array node
struct Hash{
	int capacity;				// Number of filledPages in the LRU cache
	struct Qnode** array;		// An array of the QNode's in the LRU Queue/ Cache
};

/* createLRUQueue - Creates a Queue to represent the LRU cache
 * @capacity : The total number of frames that needs to be in the cache
 */
struct Queue* createLRUQueue(int capacity){
	printf("Creating a LRU Cache of %d Frames.\n", capacity);
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q->front = NULL;
	q->rear = NULL;
	q->filledFrames = 0;
	q->totalFrames = capacity;

	return q;
}
// ========== Cache Hit and Cache Miss Data Structure and Logic ===============
// NOTE: The enQueue operation will keep all the Hash related updates
/* createHash - Create a Array based Hash table to keep all the entries of the cache
 * @Hcapacity = Number of the Filled Frames
 */
struct Hash* createHash(int Hcapacity){
	printf("Creating a Hash Map of %d Page Frames.\n", Hcapacity);
	// Allocate Memory for Hash
	struct Hash* h = (struct Hash*)malloc(sizeof(struct Hash));
	h->capacity = Hcapacity;		// This should be same as the Number of Filled Frames

	// Create an Array of Qnode pointers
	h->array = (struct Qnode**)malloc(h->capacity * sizeof(struct Qnode*));

	// Initialize the Hash array as NUll
	for(int i = 0 ; i< h->capacity; ++i){
		h->array[i] = NULL;
		printf("Hash[%d] = %p\n", i, h->array[i]);
	}

	return h;
}

// ================  Utility API's ========================
/* isCacheFull - Check if the Cache is Full or not */
int isCacheFull(struct Queue* q){
	if(q->filledFrames == q->totalFrames)
		return true;
	else
		return false;
}

/* isCacheEmpty - Check if the Cache is Full or not */
int isCacheEmpty(struct Queue* q){
	if(q->front == NULL)
		return true;
	else
		return false;
}

// ============== LRU Cache API's =========================
/* deQueue - Dequeue a node from the LRU queue
 * In LRU Scheme that node should be dequeued which is least recently used.
 * The Queue is designed with Front and Rear pointers to help us to follow this eviction scheme.
 *
 * Least Recently Used scheme can be followed if we dequeue from the Rear of the queue,
 * as it is the node which is not used recently.
 */
void deQueue(struct Queue* q){
	// If this is an empty Queue		TODO: // Lets have some utility functions to avoid code dup.
	if (q->rear == NULL)
		return;

	// If only One node present
	if(q->front == q->rear){
		q->front = NULL;
	}

	struct Qnode* temp = q->rear;	// for freeing it later
	printf("Dequeueing %d from the cache\n", q->rear->data);
	q->rear = q->rear->prev;	// New Rear will be the previous to the old rear node

	if (q->rear)
		q->rear->next = NULL;		// Set next of rear to Null to terminate the Queue

	// Free the rear node
	free(temp);

	// Reduce the number of filled frames from the LRU cache
	q->filledFrames--;
	printf("Cache capacity = %d \n", q->filledFrames);
}

/* enQueue - Puts a node in the LRU cache
 * @q : Pointer to the LRU cache Queue
 * @h : Pointer to the Hash to track Cache Hit or Miss
 * @pageNumber : page number that is being brought in to the Cache
 *
 * Basically whenever a Page is referenced from the cache, it will be either a cache Hit or Miss.
 * Logic: LRU
 * If a PageNumber is Found in the cache then its Hit.
 * 		If its a Hit then, that page should be enqueued in the Front.
 * Else its a Miss, so we need to bring that page in the cache.
 * 		If MIss, then the Page needs to be brought in to the Cache in the front.
 */
void enQueue(struct Queue* q, struct Hash* h, unsigned int pageNumber){
	//struct Qnode null;
	// Check if the Cache is Full, if yes then Dequeue a Node from the rear
	if(isCacheFull(q)){
		// remove the page from the Hash
		h->array[q->rear->data] = NULL;
		deQueue(q);
	}

	// #Cache Empty : The Page is present in the Cache so enqueue it at front
	struct Qnode* newNode = (struct Qnode*)malloc(sizeof(struct Qnode));
	newNode->data = pageNumber;
	newNode->prev = NULL;
	newNode->next = q->front;		// The newNode will be the front node, and it will be pointing to the old front node

	// If this is the first entry
	if(q->front == NULL){
		q->front = q->rear = newNode;
		newNode->next = NULL;
	}

	// If its not  the first entry
	q->front->prev = newNode;		// Since this queue is a DLL so set the previous Links too.
	q->front = newNode;				// newNode is gonna be the new Front node.

	// Increase the filled frames count by 1
	q->filledFrames = q->filledFrames+1;

	// Add Hash entry for the Page
	h->array[pageNumber] = newNode;

	printf("Enqueue new Page in the cache = %d Hash[%d] = %d \n",
						pageNumber, pageNumber, h->array[pageNumber]->data);
	printf("Cache capacity = %d \n", q->filledFrames);
	return;
}

// LRU Scheme Logic
/* LRU Policy will be called when a page with given pageNumber is referenced from the cache.
 * Now the page can be in the Cache or in the Memory.
 * 1. If the page is in the Cache, then we move the page to the
 * 	  Front of the page as this page will be the recently used page.
 * 	  LRU keeps the most recently used pages in the front.
 * 2. If the page is not in the cache then we move the page from the Memory to the
 *    Front of the cache. As now this new page will be the recently used page.
 */
void LRU_Cache_Reference(struct Queue* q, struct Hash* h, unsigned int pageNumber){
	// Get the Referenced Page or the Requested page in a Node from the hash table
	// Always check the Hash table first
	printf("Looking for %d pageNumber in the Cache\n", pageNumber);
	struct Qnode* reqPage = h->array[pageNumber];

	// Check if the page is not there in the Cache
	// Then Enqueue the page in the front
	if(reqPage == NULL){
		printf("Requested Page is NULL i.e not in the cache.\n");
		enQueue(q, h, pageNumber);
	}
	// The page is in the Cache but not in the front
	else if (reqPage != q->front) {
		printf("Requested Page is in the cache but not in the front.\n");

		// Either the req page is in the rear or in the middle
		if(reqPage->data == q->rear->data){
			// Update Rear pointer of the cache
			// If reqPage is the rear node, then change the rear node as this will be moved
			printf("q->rear->data = %d and pageNumber = %d\n", q->rear->data, reqPage->data);
			printf("Requested page is in the rear\n");
			q->rear = q->rear->prev;
			q->rear->next = NULL;
		}
		else{
			// Its in the middle
			// So UnLink the Page in the cache from its adjacent nodes
			printf("Requested page is in the middle of the cache\n");
			reqPage->prev->next = reqPage->next;
			printf("req page data = %d \n", reqPage->data);
			if(reqPage->next)
				reqPage->next->prev = reqPage->prev;
		}

		// Bring the page in the front
		reqPage->next = q->front;			// next of the reqPage will be the old front
		reqPage->prev = NULL;				// Prev will be null as reqPage will be the new Front
		reqPage->next->prev = reqPage;		// Make back link from old front to reqPage
		q->front = reqPage;					// reqpage is the new Front now
	}

}

void printCache(struct Queue* q){

	if(isCacheEmpty(q)){
		return;
	}
	else{
		printf("Cache = ");
		struct Qnode* current = q->front;
		while (current != NULL){
			printf("%d ", current->data);
			current = current->next;
		}
	}
	printf("\n");
}


int main(){
	struct Queue* q = createLRUQueue(4);

	struct Hash* h = createHash(10);

	LRU_Cache_Reference(q, h, 1);
	printCache(q);
	LRU_Cache_Reference(q, h, 2);
	LRU_Cache_Reference(q, h, 3);
	LRU_Cache_Reference(q, h, 4);
	printCache(q);
	LRU_Cache_Reference(q, h, 1);
	printCache(q);
	LRU_Cache_Reference(q, h, 5);
	printCache(q);
	LRU_Cache_Reference(q, h, 2);
	LRU_Cache_Reference(q, h, 6);
	LRU_Cache_Reference(q, h, 7);
	LRU_Cache_Reference(q, h, 8);
	LRU_Cache_Reference(q, h, 9);
	LRU_Cache_Reference(q, h, 0);
	LRU_Cache_Reference(q, h, 3);
	LRU_Cache_Reference(q, h, 1);
	printCache(q);

	// Let us print cache frames after the above referenced pages
	printf ("%d \n", q->front->data);
	printf ("%d \n", q->front->next->data);
	//printf ("%d ", q->front->next->next->data);
	//printf ("%d ", q->front->next->next->next->data);

	return 0;
}















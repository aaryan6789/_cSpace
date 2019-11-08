/* queue.c  * Created on: Jun 4, 2018 * Author: Harsh */

#include "BFS.h"

/*
// To store matrix cell coordinates
struct point{
	int x;
	int y;
};

// A node in the queue used for BFS.
struct Qnode{
	struct point pt;
	int dist;
	int visited;
	struct Qnode* next;
};

struct Queue{
	struct Qnode* front;
	struct Qnode* rear;
};
*/
// Check if a Cell is a valid cell in the Matrix or not
bool isPointValid(int x, int y, int ROW, int COL){
	if ((x >= 0) && (x < ROW) && (y >=0) && (y<COL))
		return true;
	else
		return false;
}

struct Queue* createQueue(){
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));

	q->front = NULL;
	q->rear = NULL;
	return q;
}

void enQueue(struct Queue* q, struct Qnode point){
	struct Qnode* newNode = (struct Qnode*)malloc(sizeof(struct Qnode));
	newNode->pt.x = point.pt.x;
	newNode->pt.y = point.pt.y;
	newNode->dist = point.dist;
	newNode->next = NULL;

	if((q->front == NULL)&&(q->rear == NULL)){
		q->front = q->rear = newNode;
	}
	else{
		/* Add this node at the end of the queue and also
		 * update the rear, pointing to this node */
		q->rear->next = newNode;
		q->rear = newNode;
	}

	return;
}

struct Qnode* deQueue(struct Queue* q){
	// Check for empty queue first
	if (q->front == NULL){
		printf("Queue is empty.\n");
		return NULL;
	}

	//printf("Dequeue from Front = %d \n", q->front->tnode->data);

	struct Qnode* dqPoint = (struct Qnode*)malloc(sizeof(struct Qnode));
	dqPoint = (q->front);

	// update front
	struct Qnode* newFront = q->front->next;
	q->front = newFront;

	// If newFront becomes NULL, then change rear also to NULL
	if (q->front == NULL){
		q->rear = NULL;
	}

	return dqPoint;
}


// void enQueuePt(struct Queue* q, struct point pt){
// 	struct point* newNode = (struct point*)malloc(sizeof(struct point));
// 	newNode->x = pt.x;
// 	newNode->y = pt.y;

// 	newNode->next = NULL;

// 	if((q->front == NULL)&&(q->rear == NULL)){
// 		q->front = q->rear = newNode;
// 	}
// 	else{
// 		/* Add this node at the end of the queue and also
// 		 * update the rear, pointing to this node */
// 		q->rear->next = newNode;
// 		q->rear = newNode;
// 	}

// 	return;
// }

int isQueueEmpty(struct Queue* q){
	if(q->front == NULL){
		//printf("Queue is Empty\n");
		return 1;
	}
	else{
		return 0;
	}
}

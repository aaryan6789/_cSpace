#include <stdio.h>
#include <stdlib.h>

/**
 * Animal Shelter:
 *
 * Methods:
 * enQueue()
 * dequeAny()
 * deQueueDog()
 * deQueueCat()
 */

enum animalType{
    CAT = 0,
    DOG = 1,
};

/** animalNode - To keep info about the animal */
struct animalNode{
    char name[10];
    int order;
    enum animalType type;

    struct animalNode* next;
};

struct animalQueue{
    struct animalNode* dogQueue;
    struct animalNode* catQueue;
};

// Methods
struct animalQueue* createQueue();

void enQueue(struct animalQueue* aq, char* name, enum animalType type){
    printf("Enqueue animal\n");

    // Increment order++

    struct animalNode* newNode = (struct animalNode*)malloc(sizeof(struct animalNode));

    // newNode->name = name;
    // animalNode->order = order++;
    newNode->type = type;


    if (type == 0){
        // Enqueue in Cat queue
    }
    else {
        // Enqueue in Dog Queue
    }
}

void deQueueAny(){
    // if catQueue->front->order > dogQueue->front->order
    // dequeue(dogQueue)
    // else
    // dequeue(catQueue)



}
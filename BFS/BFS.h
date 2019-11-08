/* BFS.h  * Created on: Jun 4, 2018 * Author: Harsh */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#ifndef BFS_H_
#define BFS_H_

#define bool int
#define true 1
#define false 0
#define error -1

// Stack ADT for BFS Solution
// Structure to represent a Stack (by a Linked List)
struct Lstack{
	int data;
	struct Lstack *next;
};




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

// Queue ADT
struct Queue* createQueue();
void enQueue(struct Queue* q, struct Qnode point);
struct Qnode* deQueue(struct Queue* q);
int isQueueEmpty(struct Queue* q);
bool isPointValid(int x, int y, int ROW, int COL);

// BFS Functions
int shortesDistance(int ROW, int COL, int mat[ROW][COL], struct point src, struct point dest);

#endif /* BFS_H_ */

/* shortest_path_in_binary_matrix.c  * Created on: Jun 4, 2018 * Author: Harsh */
#include "BFS.h"
#include <limits.h>
#include <string.h>

/*
Given a MxN matrix where each element can either be 0 or 1.
We need to find the shortest path between a given source cell to a dest cell.
The path can only be created out of a cell if its value is 1.
Expected time complexity is O(MN).

For example –
Input:
mat[ROW][COL]  = {{1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                  {1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
                  {1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
                  {0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
                  {1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
                  {1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
                  {1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                  {1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }};
Source = {0, 0};
Dest   = {3, 4};

Output: Shortest Path is 11
 */

/*
Method 1 : Using BFS.

1. Start from the source cell and calls BFS procedure.
2. Create a queue to store the coordinates of the matrix.
   Initialize it with the source cell.

3. Create a Boolean array: visited[][] of same size as our input matrix.
   Initialize all its elements to false.

4. LOOP till queue is not empty.
	i)  Dequeue front cell from the queue
	ii) Return if the destination coordinates have reached.
	iii) For each of its four adjacent cells,
	     if the value is 1 and they are not visited yet,
	     	 enqueue it in the queue and also mark them as visited.
 */
// These arrays are used to get row and column numbers of 4 neighbors of a given cell
// These are the coordinates corresponding to left, right, top, bottom nodes
int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};

/* function to find the shortest path between a given source cell to a destination cell.
 */
int shortesDistance(int ROW, int COL, int mat[ROW][COL], struct point src, struct point dest) {
	int ret = 0;

	bool visited[ROW][COL];
	memset(visited, 0, sizeof(visited));

	// Mark the Source Cell as Visited
	visited[src.x][src.y] = true;

	// Create a Queue
	struct Queue* q = createQueue();
	struct Qnode srcNode;
	srcNode.pt = src;
	srcNode.dist = 0;

	enQueue(q, srcNode);	// Enqueue source cell

	// Do a BFS starting from source cell
	while(!isQueueEmpty(q)){
		struct Qnode* qnode = deQueue(q);

		// If we have reached the destination cell, we are done
		if(qnode->pt.x == dest.x && qnode->pt.y == dest.y){
			ret = qnode->dist;
			printf("Distance = %d\n", ret);
			return ret;
		}

		// Else dequeue the front cell and enqueue the adjacent cells
		for(int i = 0; i<4; i++){
			int row = qnode->pt.x + rowNum[i];
			int col = qnode->pt.y + colNum[i];

			// if adjacent cell is valid, has path and not visited yet, enqueue it.
			if(isPointValid(row, col, ROW, COL) && mat[row][col] && !visited[row][col]){
				printf("Point is Valid Moving Forward\n");
				// mark cell as visited and enqueue it
				visited[row][col] = true;
				struct Qnode adjCell;
				adjCell.dist = qnode->dist + 1;
				adjCell.pt.x = row;
				adjCell.pt.y = col;

				enQueue(q, adjCell);
			}
		}
	}

	//return -1 if destination cannot be reached
	return -1;
}
/*
PS: If the weight would have been other than 1, then it would have not worked.
We use Dikstra to getthe minimum path in Graph, but since with edge weight as 1
Dijkastra boils down to just BFS.
*/

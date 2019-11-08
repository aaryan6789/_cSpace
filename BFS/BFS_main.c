/* main.c  * Created on: Jun 4, 2018 * Author: Harsh */
#include "BFS.h"

#define ROW 9
#define COL 10

int main(){

	int mat[ROW][COL] =
	    {
	        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
	        { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
	        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
	        { 1, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
	        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
	        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
	        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
	        { 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }
	    };

	struct point src;
	src.x = 0;
	src.y = 0;

	struct point dest;
	dest.x = 4;
	dest.y = 2;

	int dist = shortesDistance(ROW, COL, mat, src, dest);
	printf("Distance = %d\n", dist);

	return 0;



}

/* stack_direction.c  * Created on: Jun 24, 2018 * Author: Harsh */

#include "helper.h"

void func(int* main_local_var){
	int fun_local_var;

	if( main_local_var < &fun_local_var){
		printf("Stack is Growing Upward \n");
	}
	else {
		printf("Stack is Growing DownWard");
	}
}

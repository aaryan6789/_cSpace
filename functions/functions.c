/*
 * functions.c | Created on: Dec 21, 2017 | Author: hsahu
 */

/* Include Libraries */
#include <stdlib.h>
#include <stdio.h>

/**
 * factorial - Calculates the factorial of a number
 * factorial of a number = n*(n-1)*(n-2)*(n-3)....
 * @IP: number
 * @OP: factorial of the number
 */
int factorial(int n) {
	int result=1;

	/* For -ve and 0 */
	if (n <= 0) {
		printf("Factorial of %d = %d", n, result);
		return result;
	}

	/* For all other numbers */
	for (int i = n; i>0; i--){
		result = result*i;
	}

	printf("Factorial of %d = %d\n", n, result);
	return result;
}

int fibonacci(int n){
	return 0;
}

int main() {
	int res;

	res = factorial(-10);
	printf("Factorial= %d\n", res);
	return 0;
}

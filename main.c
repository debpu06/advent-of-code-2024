#include <stdio.h>
#include "sort.h"
#include <assert.h>

void printArray(int *array, int size){
	assert(array != NULL);
	assert(size > 0);
	for(int i = 0; i < size; i++) {
		printf("%d", array[i]);
	}
}

int main() {
	int size = 10;
	int test[] = {3,6,3,6,8,9,0,1,5,4};
	printArray(test, size);
	printf("\n");
	quicksort(test, 0, size-1);
	printArray(test, size);
	printf("\n");
	return 1;
}


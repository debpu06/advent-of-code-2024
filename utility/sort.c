#include "sort.h"
#include <stdlib.h>

void swap(int *array, int a, int b) {
	int temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

int partition(int *array, int low, int high) {
	int pivot = array[high];
	int i = low - 1;
	
	for(int j = low; j < high; j++) {
		if(array[j] <= pivot) {
			i++;
			swap(array, i, j);
		}	
	}

	swap(array, i+1, high);
	return i+1;
}

void quicksort(int *array, int low, int high){
	if(low < high) {
		int pivotIndex = partition(array, (int)low, high);
		quicksort(array, low, pivotIndex - 1);
		quicksort(array, pivotIndex + 1, high);
	} 
}




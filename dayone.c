#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

const char *FILENAME = "input.txt";
int countLines() {
	FILE *cptr = fopen(FILENAME, "r");	
	int MAX_BUFFER_LENGTH = 100;
	char buffer[MAX_BUFFER_LENGTH];
	int count = 0;
	while(fgets(buffer, sizeof(buffer), cptr) != NULL) {
		count++;
	}

	return count;
}

void extractNumbers(int *icolumn1, 
					int *icolumn2, 
					int lineCount) {
	const char *delimiter = "   ";
	FILE *fptr;

	int MAX_BUFFER_LENGTH = 100;

	fptr = fopen("input.txt", "r");
	if(fptr == NULL) {
		printf("Error opening file\n");
		return;
	}
	char buffer[MAX_BUFFER_LENGTH];
	int currentLine = 0;
	while(fgets(buffer, sizeof(buffer), fptr) != NULL) {
		char *token1 = strtok(buffer, delimiter);
		char *token2 = strtok(NULL, delimiter);

		icolumn1[currentLine] = atoi(token1);
		icolumn2[currentLine] = atoi(token2);	
		currentLine++;
	}
	quicksort(icolumn1, 0, lineCount - 1);
	quicksort(icolumn2, 0, lineCount - 1);
}

int main() {
	
	int lineCount = countLines();
	
	int line1[lineCount];
	int line2[lineCount];

	extractNumbers(line1, line2, lineCount);
	int sum = 0;
	for(int i = 0; i < lineCount; i++) {
		sum += abs(line1[i] - line2[i]);
	}
	printf("Sum: %d\n", sum);

	int max = line2[lineCount - 1];	
	int hashmap[max+1];

	for(int i = 0; i < max+1; i++) {
		hashmap[i] = 0;
	}
	for(int i = 0; i < lineCount; i++) {
		hashmap[line2[i]] += 1; 
	}
	int occuranceTotal = 0;
	for(int i = 0; i < lineCount; i++) {
		int current = line1[i];
		if(current <= max && hashmap[current] > 0) {
			printf("Occurances: %d\n", hashmap[current]);
			occuranceTotal += (hashmap[current] * current);
		}
	}
	printf("Occurance Total: %d\n", occuranceTotal);
	return 0;
}




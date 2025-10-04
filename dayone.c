#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

const char *FILENAME = "input.txt";
const size_t MAX_INPUT = 1000;

/*
* @brief Counts the number of lines in the input file.
* @return The number of lines in the file.
*/
size_t countLines() {
	FILE *cptr = fopen(FILENAME, "r");	
	assert(cptr != NULL);

	int MAX_BUFFER_LENGTH = 100;
	char buffer[MAX_BUFFER_LENGTH];
	size_t count = 0;
	while((fgets(buffer, sizeof(buffer), cptr) != NULL) 
		&& (count <= MAX_INPUT)) {
		count++;
	}

	return count;
}

/*
* @brief Extracts numbers from two columns in the input file and stores them in the provided arrays.
* @param icolumn1 Pointer to the array to store numbers from the first column.
* @param icolumn2 Pointer to the array to store numbers from the second column.
* @param lineCount The number of lines to read from the file.
*/
void extractNumbers(int *icolumn1, 
					int *icolumn2, 
					size_t lineCount) {

	assert(lineCount <= MAX_INPUT && lineCount > 0);
	assert(icolumn1 != NULL);
	assert(icolumn2 != NULL);

	const char *delimiter = "   ";
	FILE *fptr;

	int MAX_BUFFER_LENGTH = 100;

	fptr = fopen("input.txt", "r");
	assert(fptr != NULL);

	char buffer[MAX_BUFFER_LENGTH];
	size_t currentLine = 0;
	while ((fgets(buffer, sizeof(buffer), fptr) != NULL) 
		&& (currentLine <= MAX_INPUT)) {
		char *token1 = strtok(buffer, delimiter);
		char *token2 = strtok(NULL, delimiter);

		icolumn1[currentLine] = atoi(token1);
		icolumn2[currentLine] = atoi(token2);	
		currentLine++;
	}
	quicksort(icolumn1, (int)0, (int)lineCount - 1);
	quicksort(icolumn2, (int)0, (int)lineCount - 1);
}

int main() {
	
	size_t lineCount = countLines();
		
	int line1[lineCount];
	int line2[lineCount];
	assert(lineCount <= MAX_INPUT);
	extractNumbers(line1, line2, lineCount);
	int sum = 0;
	for(size_t i = 0; i < lineCount; i++) {
		sum += abs(line1[i] - line2[i]);
	}
	(void)printf("Sum: %d\n", sum);

	size_t max = line2[lineCount - 1];	
	int hashmap[max+1];

	for(size_t i = 0; i < max+1; i++) {
		hashmap[i] = 0;
	}
	for(size_t i = 0; (i < lineCount) && (i < MAX_INPUT); i++) {
		hashmap[line2[i]] += 1; 
	}
	int occuranceTotal = 0;
	for(size_t i = 0; (i < lineCount) && (i < MAX_INPUT); i++) {
		size_t current = line1[i];
		if(current <= max && hashmap[current] > 0) {
			occuranceTotal += (hashmap[current] * current);
		}
	}
	(void)printf("Occurance Total: %d\n", occuranceTotal);

	return 0;
}




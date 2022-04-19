/*
 ============================================================================
 Name        : Q2.c
 Author      : Matthew Chan (58909152)
 Description : Question 2, Lab 2 (L1D)

 Vector Size (50 million) Result:
 	 0 0 0 0 0 0 0 0 0 0
	 Execution time: 0.000166 ms

Vector Size (1 billion) Result:
	Not enough memory for arrays: a or b.
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* addVec2(int* a, int* b, int size);

int main(void) {
	// Init variables
	clock_t start, end;
	double total_time;
	const int ARRAY_SIZE = 50000000;
	int* a = (int*) calloc(ARRAY_SIZE, sizeof(int));
	int* b = (int*) calloc(ARRAY_SIZE, sizeof(int));
	int* c = NULL;

	// Check if memory successfully allocated
	if (a == NULL || b == NULL) {
		// Memory allocation failed
		printf("Not enough memory for arrays: a or b.");
		fflush(stdout);
		return EXIT_FAILURE;
	}


	// Start timer
	start = clock();

	// Add vectors sequentially
	c = addVec2(a, b, ARRAY_SIZE);

	// Check if memory successfully allocated
	if (c == NULL) {
		// Memory allocation failed
		printf("Not enough memory for array: c.");
		fflush(stdout);
		return EXIT_FAILURE;
	}

	// Finish timer
	end = clock();

	// Calculate time
	total_time = ((double)(end - start) / CLOCKS_PER_SEC) / 1000;

	// Successful run & print results
	for (int i = 0; i < 10; i++) {
		printf("%d ", c[i]);
	}

	printf("\nExecution time: %f ms", total_time);
	fflush(stdout);

	// Free memory
	free(a);
	free(b);
	free(c);
	return EXIT_SUCCESS;
}

int* addVec2(int* a, int* b, int size) {
	int* c = (int*) calloc(size, sizeof(int));
	int* cArrPtr = NULL;

	// If memory fails to allocate return NULL
	if (c == NULL) {
		return NULL;
	}

	// If memory successfully allocates compute and return result
	for (cArrPtr = c; cArrPtr < (c + size); cArrPtr++) {
		*cArrPtr = *a + *b;
		a++;
		b++;
	}

	return c;
}

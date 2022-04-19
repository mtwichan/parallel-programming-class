/*
 ============================================================================
 Name        : Q1.c
 Author      : Matthew Chan (58909152)
 Description : Question 1, Lab 2 (L1D)

 Vector Size (50 million) Result:
 	 0 0 0 0 0 0 0 0 0 0
	 Execution time: 0.000163 ms

Vector Size (1 billion) Result:
	Not enough memory.
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void addVec(int* C, int* A, int* B, int size);

int main(void) {
	// Init variables
	clock_t start, end;
	double total_time;
	const int ARRAY_SIZE = 50000000;
	int* A = (int*) calloc(ARRAY_SIZE, sizeof(int));
	int* B = (int*) calloc(ARRAY_SIZE, sizeof(int));
	int* C = (int*) calloc(ARRAY_SIZE, sizeof(int));

	// Check if memory successfully allocated
	if (A == NULL || B == NULL || C == NULL) {
		// Memory allocation failed
		printf("Not enough memory.");
		fflush(stdout);
		return EXIT_FAILURE;
	}


	// Start timer
	start = clock();

	// Add vectors sequentially
	addVec(C, A, B, ARRAY_SIZE);

	// Finish timer
	end = clock();

	// Calculate time
	total_time = ((double)(end - start) / CLOCKS_PER_SEC) / 1000;

	// Successful run & print results
	for (int i = 0; i < 10; i++) {
		printf("%d ", C[i]);
	}
	printf("\nExecution time: %f ms", total_time);
	fflush(stdout);

	// Free memory
	free(A);
	free(B);
	free(C);
	return EXIT_SUCCESS;
}

void addVec(int* C, int* A, int* B, int size) {
	while (size--) {
		*C = *A + *B;
		A++;
		B++;
		C++;
	}

	return;
}
//}

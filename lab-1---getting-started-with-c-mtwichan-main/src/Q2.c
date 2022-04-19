/*
 ============================================================================
 Name        : Q2.c
 Author      : Matthew Chan (58909152)
 Description : Question 2, Lab 1 (L1D)

 Vector Size (1 million) Result:
	 Sum: 0
	 Execution time: 0.01 sec

 Vector Size (10 million) Result:
	 Sum: 0
	 Execution time: 0.07 sec

 Vector Size (50 million) Result:
 	 Sum: 0
 	 Execution time: 0.33 sec

 Vector Size (100 million) Result:
	Sum: 0
	Execution time: 0.65 sec

Vector Size (1 billion) Result:
	Not enough memory.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	// Init variables
	clock_t start, end;
	double total_time;
	const int ARRAY_SIZE = 100000000;
	int sum = 0;
	int* A = (int*) malloc(ARRAY_SIZE * sizeof(int));
	int* B = (int*) malloc(ARRAY_SIZE * sizeof(int));
	int* C = (int*) malloc(ARRAY_SIZE * sizeof(int));

	// Check if memory successfully allocated
	if (A == NULL || B == NULL || C == NULL) {
		// Memory allocation failed
		printf("Not enough memory.");
		fflush(stdout);
		return EXIT_FAILURE;
	}

	// Start timer
	start = clock();

	// Run algorithim
	for (int i = 0; i < ARRAY_SIZE; i++) {
		A[i] = i * 3;
		B[i] = -i * 3;
		C[i] = A[i] + B[i];
	}

	for (int i = 0; i < ARRAY_SIZE; i++) {
		sum = sum + C[i];
	}

	// Finish timer
	end = clock();

	// Calculate time
	total_time = (double)(end - start) / CLOCKS_PER_SEC;

	// Successful run
	printf("Sum: %d \n", sum);
	printf("Execution time: %.2f sec", total_time);
	fflush(stdout);

	return EXIT_SUCCESS;
}

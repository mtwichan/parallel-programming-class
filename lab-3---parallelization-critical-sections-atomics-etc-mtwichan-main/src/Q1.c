/*
 ============================================================================
 Name        : q1.c
 Author      : Matthew Chan
 Description : Lab 3 - Q1 code

Sample run 1 (4 threads):

Serial code processed in: 0.120000 seconds
Serial vector last item: 49999999

Parallel code processed in: 0.037000 seconds
Parallel vector last item: 49999999

Sample run 2 (3 threads):

Serial code processed in: 0.096000 seconds
Serial vector last item: 49999999
Error: parallel code, size of array must be an even number and divisible by the number of threads.

Sample run 3 (5 billion samples):
Error: serial code, malloc failed to allocate memory in serial code.
Error: parallel code, malloc failed to allocate memory in parallel code.
 ============================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <time.h>


/** Serial Code **/
int* vecCreate(int size) {
	// Init variables
	int* vector = malloc(size * sizeof(int));
	int i = 0;

	// Error checking
	if (vector == NULL) {
		printf("Error: serial code, malloc failed to allocate memory in serial code.\n");
		return NULL;
	}

	// Assign values to array
	for (i = 0; i < size; i++) {
		vector[i] = i;
	}

	return vector;
}

/** Parallel Code **/
int* vecCreateOpenMP(int size, int num_thread) {
	// Init variables
	int* vector = malloc(size * sizeof(int));

	// Error checking
	if (vector == NULL) {
		printf("Error: parallel code, malloc failed to allocate memory in parallel code.\n");
		return NULL;
	}

	if ((size % num_thread) != 0) {
		printf("Error: parallel code, size of array must be an even number and divisible by the number of threads.\n");
		return NULL;
	}

	// Assign values to array in parallel
	#pragma omp parallel num_threads(num_thread)
	{
		int thread_id = omp_get_thread_num();
		int thread_ele =  size / num_thread;
		int start = thread_id * thread_ele;
		int end = start + thread_ele - 1;

		for (int i = start; i <= end; i++) {
			vector[i] = i;
		}

	}
	return vector;
}

// Main method

int main() {
	// Init variables
	int size = 500000000;
	int num_thread = 3;
	int* vector_serial = NULL;
	int* vector_parallel = NULL;
	double start_time = 0.0;
	double end_time = 0.0;

	// Serial testing code
	start_time = omp_get_wtime();
	vector_serial = vecCreate(size);
	end_time = omp_get_wtime();
	if (vector_serial != NULL) {
			printf("Serial code processed in: %f seconds\n", end_time - start_time);
			printf("Serial vector last item: %d\n", vector_serial[size - 1]);
		}
	free(vector_serial);

	// Parallel testing code
	start_time = omp_get_wtime();
	vector_parallel = vecCreateOpenMP(size, num_thread);
	end_time = omp_get_wtime();
	if (vector_parallel != NULL) {
		printf("Parallel code processed in: %f seconds\n", end_time - start_time);
		printf("Parallel vector last item: %d\n", vector_parallel[size - 1]);
	}
	free(vector_parallel);
}


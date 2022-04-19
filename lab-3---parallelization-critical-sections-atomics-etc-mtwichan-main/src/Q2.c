/*
 ============================================================================
 Name        : q1.c
 Author      : Matthew Chan
 Description : Lab 3 - Q2 code

Atomic
2 Thread Run:
	1K Results:
	Parallel code time: 0.001000 seconds
	Parallel sum: 1001
	Parallel threads: 2
	Serial code time: 0.000000 seconds
	Serial sum: 1001

	1M Results:
	Parallel code time: 0.003000 seconds
	Parallel sum: 1000102
	Parallel threads: 2
	Serial code time: 0.004000 seconds
	Serial sum: 1000102

4 Thread Run:
	1K Results:
	Parallel code time: 0.001000 seconds
	Parallel sum: 2017
	Parallel threads: 4
	Serial code time: 0.000000 seconds
	Serial sum: 2017

	1M Results:
	Parallel code time: 0.003000 seconds
	Parallel sum: 2000232
	Parallel threads: 4
	Serial code time: 0.008000 seconds
	Serial sum: 2000232

8 Thread Run:
	1K Results:
	Parallel code time: 0.003000 seconds
	Parallel sum: 4026
	Parallel threads: 8
	Serial code time: 0.000000 seconds
	Serial sum: 4026

	1M Results:
	Parallel code time: 0.004000 seconds
	Parallel sum: 4000009
	Parallel threads: 8
	Serial code time: 0.015000 seconds
	Serial sum: 4000009

16 Thread Run:
	1K Results:
	Parallel code time: 0.004000 seconds
	Parallel sum: 8038
	Parallel threads: 16
	Serial code time: 0.000000 seconds
	Serial sum: 8038

	1M Results:
	Parallel code time: 0.008000 seconds
	Parallel sum: 8000024
	Parallel threads: 16
	Serial code time: 0.030000 seconds
	Serial sum: 8000024

Critical
2 Thread Run:
	1K Results:
	Parallel code time: 0.001000 seconds
	Parallel sum: 1001
	Parallel threads: 2
	Serial code time: 0.000000 seconds
	Serial sum: 1001

	1M Results:
	Parallel code time: 0.003000 seconds
	Parallel sum: 1000102
	Parallel threads: 2
	Serial code time: 0.003000 seconds
	Serial sum: 1000102

4 Thread Run:
	1K Results:
	Parallel code time: 0.001000 seconds
	Parallel sum: 2017
	Parallel threads: 4
	Serial code time: 0.000000 seconds
	Serial sum: 2017

	1M Results:
	Parallel code time: 0.003000 seconds
	Parallel sum: 2000232
	Parallel threads: 4
	Serial code time: 0.007000 seconds
	Serial sum: 2000232

8 Thread Run:
	1K Results:
	Parallel code time: 0.001000 seconds
	Parallel sum: 4026
	Parallel threads: 8
	Serial code time: 0.000000 seconds
	Serial sum: 4026

	1M Results:
	Parallel code time: 0.005000 seconds
	Parallel sum: 4000009
	Parallel threads: 8
	Serial code time: 0.016000 seconds
	Serial sum: 4000009

16 Thread Run:
	1K Results:
	Parallel code time: 0.002000 seconds
	Parallel sum: 8038
	Parallel threads: 16
	Serial code time: 0.000000 seconds
	Serial sum: 8038

	1M Results:
	Parallel code time: 0.009000 seconds
	Parallel sum: 8000024
	Parallel threads: 16
	Serial code time: 0.034000 seconds
	Serial sum: 8000024

Atomic appears to be faster because it has less over head.
 ============================================================================
 */
#include <stdio.h>       
#include <stdlib.h>
#include <omp.h>     
#include <time.h>
//This defines the number of threads that will be used for the problem
/** @todo adjust this ! */
#define NUM_THREADS 16

// The array size must be a multiple of the number of thread (for this example)
// otherwise bad things will happen (ie one thread attempting to access data
// outside of the bounds of the array)
#define VALUE 1000  /** @todo adjust this value to increase number of elements */
#define ARRAY_SIZE (NUM_THREADS * VALUE)


/**
 * Function to run as an OpenMP parallel section 
 * 
 * Recall that each thread will work through only a portion of the array
 * Each thread, will process only a part of the global array and it's 
 * starting position will be controlled by thread number and range (size of 
 * array divided by number of available threads).
 **/
void add_vector(int* A, int size, int* global_sum, int num_threads) {

	#pragma omp parallel num_threads(num_threads)
	{
		int thread_id = omp_get_thread_num();
		int thread_ele = size / NUM_THREADS;
		int start = thread_id * thread_ele;
		int end = start + thread_ele - 1;
		int local_sum = 0;

		for (int i = start; i <= end; i++) {
			local_sum += A[i];
		}
		#pragma omp critical
			*global_sum += local_sum;
	}
}

/* like any C program, program's execution begins in main */
int main(int argc, char* argv[])
{
   /** @todo declare A and global_sum in main (with correct type)*/
	int* A = malloc(ARRAY_SIZE * sizeof(int));
	int global_sum = 0;
	int i = 0;
	double start_time = 0.0;
	double end_time = 0.0;

	// Error checking
	if (A == NULL) {
		printf("Error: malloc does not have enough memory for desired array size.");
		return 1;
	}

	if ((ARRAY_SIZE % NUM_THREADS) != 0) {
			printf("Error: parallel code, size of array must be an even number and divisible by the number of threads.\n");
			return 1;
		}

   /** @todo Initial A with random values */
   // for a given array size, generated random values for
   // each location of A
	for (i = 0; i <= ARRAY_SIZE; i++) {
		A[i] = rand() % 2;
	}

   /** @todo launch your parallel code! **/
   /** +2, +1 (timing) */
	start_time = omp_get_wtime();
	add_vector(A, ARRAY_SIZE, &global_sum, NUM_THREADS);
	end_time = omp_get_wtime();

	printf("Parallel code time: %f seconds\n", end_time - start_time);
	printf("Parallel sum: %d\n", global_sum);
	printf("Parallel threads: %d\n", NUM_THREADS);

   /** @todo calculate sum serially and check results.
    * print out sums and timing information with number of threads)
    **/
	global_sum = 0;
	start_time = omp_get_wtime();
	for (i = 0; i < ARRAY_SIZE; i++) {
			global_sum += A[i];
		}
	end_time = omp_get_wtime();

	printf("Serial code time: %f seconds\n", end_time - start_time);
	printf("Serial sum: %d", global_sum);
	free(A);
   exit(0);
}

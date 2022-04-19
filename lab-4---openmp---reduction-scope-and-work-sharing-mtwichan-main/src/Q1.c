/*
 ============================================================================
 Name        : q1.c
 Author      : Matthew Chan
 Description : Lab 4 - Q1 code

Reduction
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
	Parallel code time: 0.002000 seconds
	Parallel sum: 4026
	Parallel threads: 8
	Serial code time: 0.000000 seconds
	Serial sum: 4026

	1M Results:
	Parallel code time: 0.005000 seconds
	Parallel sum: 4000009
	Parallel threads: 8
	Serial code time: 0.014000 seconds
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
	Serial code time: 0.033000 seconds
	Serial sum: 8000024

How does this performance compare to the previous implementation using a critical section? What is the key difference when using reduction?

Reduction has much lower overhead than creating a critical section and threads do not
need to queue and acquire locks sequentially like a critical section, thus it is faster.
It does not need to worry about synchronization thus it is also faster than the atomic method.
 ============================================================================
 */
#include <stdio.h>       
#include <stdlib.h>
#include <omp.h>     

//This defines the number of threads that will be used for the problem
/** @todo adjust this ! */
#define NUM_THREADS 2

// The array size must be a multiple of the number of thread (for this example)
// otherwise bad things will happen (ie one thread attempting to access data
// outside of the bounds of the array)
#define VALUE 1000000  /** @todo adjust this value to increase number of elements */
#define ARRAY_SIZE (NUM_THREADS * VALUE)


/**
 * Function to run as an OpenMP parallel section 
 * 
 * Recall that each thread will work through only a portion of the array
 * Each thread, will process only a part of the global array and it's 
 * starting position will be controlled by thread number and range (size of 
 * array divided by number of available threads). The portion of the array
 * that is being processed is still determined by the thread number
 * and needs to be evenly divisible.
 * 
 * @todo this function needs to be called using a parallel directive using reduction.
 * This is similar to what we did in lab 3, but there, needed to manually reduce
 * the sum.
 * @param input - array A
 * @param size - the size of the array (ie number of elements)
 * 
 * @return the partial sum for the thread 
 **/
int add_vector(int * A, int size);

/* like any C program, program's execution begins in main */
//int main(int argc, char* argv[])
//{
//    /** @todo declare A and global_sum in main (with correct type)*/
//	int* A = malloc(ARRAY_SIZE * sizeof(int));
//	int global_sum = 0;
//	int i = 0;
//	double start_time = 0.0;
//	double end_time = 0.0;
//    /** @todo Initial A with random values */
//    // for a given array size, generated random values for
//    // each location of A
//    for (i = 0; i < ARRAY_SIZE; i ++)
//    {
//    	/** @todo Initial A with random values */
//    	A[i] = rand() % 2;
//
//    }
//
//
//    /** @todo launch your parallel code!
//    *           As you are now using the reduction operator,
//    *           do we need to protect global_sum in a crtical section?
//    *           timing!
//    **/
//    start_time = omp_get_wtime();
//    global_sum = add_vector(A, ARRAY_SIZE);
//    end_time = omp_get_wtime();
//
//
//    /** @todo
//     * Check the results to make sure the sums are working!
//     * Print out sums and timing information with number of threads)
//     * Use your code from last week - Lab 3 - Q2
//     **/
//	printf("Parallel code time: %f seconds\n", end_time - start_time);
//	printf("Parallel sum: %d\n", global_sum);
//	printf("Parallel threads: %d\n", NUM_THREADS);
//
//	global_sum = 0;
//	start_time = omp_get_wtime();
//	for (i = 0; i < ARRAY_SIZE; i++) {
//			global_sum += A[i];
//		}
//	end_time = omp_get_wtime();
//
//	printf("Serial code time: %f seconds\n", end_time - start_time);
//	printf("Serial sum: %d", global_sum);
//
//	free(A);
//    exit(0);
//}
//
///** @todo complete this function */
//int add_vector(int * A, int size)
//{
//    // this will work through only a portion of the array
//    // Each thread, will process only a part of the global array
//    // and it's starting position will be controlled by thread
//    // number and range.
//    //
//
//	int local_sum = 0;
//		#pragma omp parallel reduction(+:local_sum) num_threads(NUM_THREADS)
//		{
//			int thread_id = omp_get_thread_num();
//			int thread_ele = size / NUM_THREADS;
//			int start = thread_id * thread_ele;
//			int end = start + thread_ele - 1;
//
//			for (int idx = start; idx <= end; idx++) {
//				local_sum += A[idx];
//			}
//		}
//	return local_sum;
//}

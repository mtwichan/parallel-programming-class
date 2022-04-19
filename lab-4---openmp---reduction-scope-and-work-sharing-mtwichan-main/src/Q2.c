/*
 ============================================================================
 Name        : q2.c
 Author      : Matthew Chan
 Description : Lab 4 - Q2 code

Results (VALUE = 10000000):
Execution time: 0.000054 ms
Parallel threads: 8
18508 32834 34893 40836 51426 33850 40108 10452 14937 10263
Sums all good!

Results (VALUE = 50000000):
Not enough memory.
 ============================================================================
 */

/**
* Starter code for lab 4 - Q2
* @todo Please read the comments in the code to understand what needs to be done
* Note: 
*       -use can use slicing method of lab 3 - Q2
*       -time with omp_get_wtime() which returns the number of seconds that have passed since some 
*       time in the past. For details on taking timings, see Section 2.6.4 of the textbook PACHECO-11. 
**/
#include <stdio.h>       
#include <stdlib.h>
#include <omp.h>

//This defines the number of threads that will be used for the problem
/** @todo adjust this ! */
#define NUM_THREADS 8

// The array size must be a multiple of the number of thread (for this example)
// otherwise bad things will happen (ie one thread attempting to access data
// outside of the bounds of the array)
#define VALUE 10000000 /** @todo adjust this value to increase number of elements */
#define ARRAY_SIZE (NUM_THREADS * VALUE)


/** 
 * make sure size is shared across all threads,
 * and idx is private (each thread will need it's own copy)
 **/
//void add_vector(int* C, int* A, int* B, int size);

/* like any C program, program's execution begins in main */
//int main(int argc, char* argv[])
//{
//
//    int* A = malloc(ARRAY_SIZE * sizeof(int));
//    int* B = malloc(ARRAY_SIZE * sizeof(int));
//    int* C = malloc(ARRAY_SIZE * sizeof(int));
//
//    double start_time = 0.0;
//    double end_time = 0.0;
//
//    if ((A == NULL) || (B == NULL) || (C == NULL)) {
//    	printf("Not enough memory.");
//    	free(A);
//    	free(B);
//    	free(C);
//    	return 1;
//    }
//    // for a given array size, generated random values for
//    // each location of A and B
//    for (int i = 0; i < ARRAY_SIZE; i++)
//    {
//        A[i] = rand();
//	    B[i] = rand();
//    }
//
//    /** Compare this to how this was accomplished with pThreads.
//    **/
//    /** @todo add timing information for this call*/
//    start_time = omp_get_wtime();
//    add_vector(C, A, B, ARRAY_SIZE);
//    end_time = omp_get_wtime();
//
//	printf("Execution time: %f ms\n", (end_time - start_time) / 1000.0);
//	printf("Parallel threads: %d\n", NUM_THREADS);
//
//    //check results
//    char bad = 0;
//
//    for (int i = 0; i < ARRAY_SIZE; i ++)
//    {
//	    if (A[i] + B[i] != C[i])
//	    {
//	    	    printf("Error at %d\n",i);
//		    bad |= 1;
//	    }
//	    else {
//	    	if (i < 10) {
//	    		printf("%d ", C[i]);
//	    	}
//	    }
//    }
//    if (bad)
//    {
//	    printf("\nSums failed\n");
//    }
//    else
//    {
//	    printf("\nSums all good!\n");
//    }
//    free(A);
//    free(B);
//    free(C);
//    exit(0);
//}

/** 
 * make sure size is shared across all threads,
 * and idx is private (each thread will need it's own copy)
 * *parallelize the slicing and addition inside! 
 * @todo based on the thread id and number of threads, you will need to slice up the array so that each thread is working on its own section.
 * @todo make sure to use private for idx to ensure that each thread gets its own copy
 * @todo make sure to use set the number of threads for the parallel section
 * @todo make sure to use only the parallel directive (NOT the parallel for; that's the next question)
 **/
//void add_vector(int* C, int* A, int* B, int size)
//{
//    int idx = 0;    //use this for the array index, but make sure that each thread gets its own private copy!
//	#pragma omp parallel num_threads(NUM_THREADS) private(idx) shared(size)
//    {
//    	int thread_id = omp_get_thread_num();
//    	int thread_ele = size / NUM_THREADS;
//    	int start = thread_id * thread_ele;
//    	int end = start + thread_ele - 1;
//
//    	for (idx = start; idx <= end; idx++) {
//    		C[idx] = A[idx] + B[idx];
//    	}
//    }
//
//    /** @todo parallelize the addition of c = a + b across the threads*/
//}

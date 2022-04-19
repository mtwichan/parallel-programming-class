/*
 ============================================================================
 Name        : q3.c
 Author      : Matthew Chan
 Description : Lab 4 - Q3 code

Results (VALUE = 10000000):
Execution time: 0.000008 ms
Parallel threads: 8
18508 32834 34893 40836 51426 33850 40108 10452 14937 10263

Results (VALUE = 50000000):
Not enough memory.

How does this performance compare to the previous implementation using a critical section?
Execution time is much faster using the parallel for than reduction.

What is the key difference when using reduction?
Reduction is used for atomic operations, and when used with a for loop, the
threads all run the same for loop multiple times. Whereas the omp for loop operation
runs the same for loop for all threads but distributes the work.

Does the size of the array now need to be a multiple of the number of threads?
No, it will automatically allocate the un even amount of work per thread.

 ============================================================================
 */

/**
* Starter code for lab 4 - Q3
* Use parallel for with private variable -
* Go back to lab 4 - Q2 (now done with OpenMP and parallel for directive)
* @todo Please read the comments in the code to understand what needs to be done
* 
* Notes:
* -Does the size of the array now need to be a multiple of the number of threads?
* -time and compare with Q2
*
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
#define VALUE 1000000  /** @todo adjust this value to increase number of elements */
#define ARRAY_SIZE (VALUE)

//this is the length of the slice (ARRAY_SIZE/NUM_THREADS)
int length;

/** 
 * make sure size is shared across all threads,
 * and idx is private (each thread will need it's own copy)
 **/
//void add_vector(int* C, int* A, int* B, int size);

/* like any C program, program's execution begins in main */
//int main(int argc, char* argv[])
//{
//
//	int* A = malloc(ARRAY_SIZE * sizeof(int));
//	int* B = malloc(ARRAY_SIZE * sizeof(int));
//	int* C = malloc(ARRAY_SIZE * sizeof(int));
//
//	double start_time = 0.0;
//	double end_time = 0.0;
//
//	if ((A == NULL) || (B == NULL) || (C == NULL)) {
//		printf("Not enough memory.");
//		free(A);
//		free(B);
//		free(C);
//		return 1;
//	}
//
//    // for a given array size, generated random values for
//    // each location of A and B (+4)
//    for (int i = 0; i < ARRAY_SIZE; i ++)
//    {
//
//        A[i] = rand();
//	    B[i] = rand();
//    }
//
//    /** Compare this to how this was accomplished with pThreads (or even OpenMP
//    * where we had to manually slice the array.  Parallel for is a very powerful
//    * construction
//    **/
//    /** @todo add timing information for this call.  Compare this to Q2.*/
//	start_time = omp_get_wtime();
//	add_vector(C, A, B, ARRAY_SIZE);
//	end_time = omp_get_wtime();
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
//	    } else {
//				if (i < 10) {
//					printf("%d ", C[i]);
//				}
//	    }
//    }
//    if (bad)
//    {
//	    printf("Sums failed\n");
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
 **/
//void add_vector(int* C, int* A, int* B, int size)
//{
//    int idx = 0;
//    /** @todo parallel code goes here! **/
//	#pragma omp parallel for num_threads(NUM_THREADS) private(idx) shared(size)
//		for (idx=0; idx < size; idx++) {
//			C[idx] = A[idx] + B[idx];
//		}
//
//}

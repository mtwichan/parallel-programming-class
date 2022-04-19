/*
 ============================================================================
 Name        : Q5.c
 Author      : Matthew Chan (58909152)
 Description : Question 5, Lab 2 (L1D)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv[]) {
	int numThreads, tid;
	/* This creates a team of threads; each thread has own copy of variables  */
	#pragma omp parallel private(numThreads, tid)
	{
		tid = omp_get_thread_num();
		printf("Hello World from thread number %d\n", tid);

		/* The following is executed by the master thread only (tid=0) */
		if (tid == 0) {
			numThreads = omp_get_num_threads();
			printf("Number of threads is %d\n", numThreads);
		}
	}
	return 0;
}

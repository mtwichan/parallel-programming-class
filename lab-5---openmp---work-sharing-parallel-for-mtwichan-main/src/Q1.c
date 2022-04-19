/*
 ============================================================================
 Name        : q1.c
 Author      : Matthew Chan
 Description : Lab 5 - q1 code

* Results:
	#define NRA 120
	#define NCA 130
	#define NCB 110
	#define NUM_THREADS 4

	Starting serial multiplication ...
	Execution time (Serial): 0.005000s
	Starting parallel multiplication...
	Execution time (Parallel): 0.003000s
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define NUM_THREADS 4           /** number of threads to request **/

#define NRA 120                  /** number of rows in matrix A **/
#define NCA 130                  /** number of columns in matrix A **/
#define NCB 110                  /** number of columns in matrix B **/

//int main(void){
//
//    int i, j, k;
//
//    double a[NRA][NCA];         /** matrix A to be multiplied **/
//	double b[NCA][NCB];         /** matrix B to be multiplied **/
//	double c[NRA][NCB];         /** result matrix C **/
//	double start_time, end_time, total_time;
//	time_t start_t, end_t;
//
//
//    /*** Spawn a parallel region explicitly scoping all variables
//     * Be mindful of what needs to be shared and what needs to be private
//     **/
//	/** @todo complete the operations for the matrix multiplication (start with serial implementation first)
//    /** @todo initialization of matrix can be parallelized!!
//    * using parallel for as well! **/
//
//	// Serial
//	// Init matrices
//	printf("Starting serial multiplication ...\n");
//	start_t = clock();
//	for (i = 0; i < NRA; i++) {
//		for (j = 0; j < NCA; j++) {
//			a[i][j] = i + j;
//		}
//	}
//
//	for (i = 0; i < NCA; i++) {
//		for (j = 0; j < NCB; j++) {
//			b[i][j] = i * j;
//		}
//	}
//
//	for (i = 0; i < NRA; i++) {
//		for (j = 0; j < NCB; j++) {
//			c[i][j] = 0;
//		}
//	}
//
//	// Matrix multiplication
//	for (i = 0; i < NRA; i++) {
//		for (j = 0; j < NCB; j++) {
//			for (k = 0; k < NCA; k++) {
//				c[i][j] += a[i][k] * b[k][j];
//			}
//		}
//	}
//	end_t = clock();
//	total_time = ((double)(end_t - start_t) / CLOCKS_PER_SEC);
//	printf("Execution time (Serial): %fs\n", total_time);
//
//	/*** Print results ***/
//	printf("Result Matrix Serial:\n");
//	for (i = 0; i < NRA; i++) {
//		for (j = 0; j < NCB; j++)
//			printf("%6.2f   ", c[i][j]);
//		printf("\n");
//	}
//
//	// Parallel
//	printf("Starting parallel multiplication... \n");
//	start_time = omp_get_wtime();
//	#pragma omp parallel num_threads(NUM_THREADS) private(i, j) shared(a, b, c)
//	{
//		#pragma omp for collapse(2)
//		for (i = 0; i < NRA; i++) {
//				for (j = 0; j < NCA; j++) {
//					a[i][j] = i + j;
//				}
//			}
//
//
//		#pragma omp for collapse(2)
//		for (i = 0; i < NCA; i++) {
//				for (j = 0; j < NCB; j++) {
//					b[i][j] = i * j;
//				}
//			}
//
//		#pragma omp for collapse(2)
//		for (i = 0; i < NRA; i++) {
//				for (j = 0; j < NCB; j++) {
//					c[i][j] = 0;
//				}
//			}
//
//		// Matrix multiplication
//		#pragma omp for collapse(3)
//		for (i = 0; i < NRA; i++) {
//			for (j = 0; j < NCB; j++) {
//				for (k = 0; k < NCA; k++) {
//					c[i][j] += a[i][k] * b[k][j];
//				}
//			}
//		}
//	}
//	end_time = omp_get_wtime();
//	printf("Execution time (Parallel): %fs\n", (end_time - start_time));
//
//	/*** Print results ***/
//	printf("Result Matrix Parallel:\n");
//	for (i = 0; i < NRA; i++) {
//		for (j = 0; j < NCB; j++)
//			printf("%6.2f   ", c[i][j]);
//		printf("\n");
//	}
//return 0;
//}

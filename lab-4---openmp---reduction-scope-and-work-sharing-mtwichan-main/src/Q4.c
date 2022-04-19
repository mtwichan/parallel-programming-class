/*
 ============================================================================
 Name        : q4.c
 Author      : Matthew Chan
 Description : Lab 4 - q4 code

1. If we try to parallelize the for i loop (the outer loop in the serial count sort function), which variables should be private and which should be shared within the parallel implementation?
- shared(i, temp, count)
- private(j)

2. If we parallelize the for i loop using the scoping you specified in the previous part, are there any loop-carried dependences? Explain your answer in the comments in the header. (Question 2 - 2 marks)
Yes, i, temp and count would be loop carried dependencies because these variables are used in both for loops.

4. Add timing code to time both the serial and parallel implementations. Report the timing for both the serial and parallel implementation with n=10,000 and 8 threads. Report the results in the comments in your code.

Results:
Execution time (Serial): 0.462000s
Execution time (Parallel): 0.815000s
Parallel threads: 8

It appears that the overhead to create the parallel threads causes the parallel time to be slower. I tried this out with a greater ARRAY_SIZE and saw that the parallel was faster than the sequential.

5. What is the advantage to using the parallel for implementation as compared to the manual slicing that was done in previous questions/labs? Think about the size of the input and relationship to the number of threads in terms of a successful parallelization. Does this hold true for the parallel for implementation? Test your assumption. (Question 3 - 2 marks)
The code is much easier to write firstly. The main advantage is that you do not have to worry about the manual slicing with the parallel for implementation and that the manual slicing method relies on the
threads being able to be divided by the threads, which means it will not work in cases where the thread can not be divided.
 ============================================================================
 */

/**
* Starter code for lab 4 - Q4 - based on PACHECO-11 Q5.3(a,b,d) p. 268): 
* @todo develop a function called count_sort_parallel that will be the 
* parallel implementation of the serial version.  Inside the function
* you will need to use the appropriate omp directives. 
**/
#include <stdio.h>       
#include <stdlib.h>
#include <omp.h>
#include <string.h>             //need for memcpy
#include<time.h>

#define ARRAY_SIZE 10000
#define NUM_THREADS 8

/**
 * @param a[] - the input array to sort
 * @param n - the number of elements in the array
 */
void count_sort_serial(int a[], int n);

/**
 * @param a[] - the input array to sort
 * @param n - the number of elements in the array
 */
void count_sort_parallel(int a[], int n);

/* like any C program, program's execution begins in main */
int main(int argc, char* argv[])
{

    //Create two arrays - sort one with parallel sort, sort the other with serial sort
    int A[ARRAY_SIZE];
    int B[ARRAY_SIZE];
    double start_time = 0.0;
	double end_time = 0.0;
	double total_time = 0.0;
    clock_t start, end;

     // for a given array size, generated random values for
    // each location of A and B
    for (int i = 0; i < ARRAY_SIZE; i ++)
    {
    	/** Initialize A, B with random values (A and B should be the same) */
        A[i] = rand();
        B[i] = A[i];
    }

    /** @todo add timing information **/

    start = clock();
    count_sort_serial(A, ARRAY_SIZE);
    end = clock();
    total_time = ((double)(end - start) / CLOCKS_PER_SEC);
    printf("Execution time (Serial): %fs\n", total_time);

    start_time = omp_get_wtime();
    count_sort_parallel(B, ARRAY_SIZE);
    end_time = omp_get_wtime();

	printf("Execution time (Parallel): %fs\n", (end_time - start_time));
	printf("Parallel threads: %d\n", NUM_THREADS);

    //compare your results - will print message if the serial sort and parallel sort
    //produce different results.
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (A[i] != B[i])
        {
            printf("Bad value at idx:%d A:%d B:%d \n", i, A[i], B[i]);
        }
    }

}

void count_sort_serial(int a[], int n) 
{
	int i, j, count;
	int* temp = malloc(n * sizeof(int));
	for (i = 0; i < n; i++){
		//count all elements < a[i]
		count = 0;
		for (j = 0; j < n; j++)
			if(a[j]<a[i] ||(a[j]==a[i] && j<i))	
				count++;
		//place a[i] at right order
		temp[count] = a[i];
	}
    //this copies the temp results back into the original array
	memcpy(a, temp, n * sizeof(int));
	free(temp);
}

/** @todo complete this function */
void count_sort_parallel(int a[], int n) 
{
	int i, j, count;
	int* temp = malloc(n * sizeof(int));
	for (i = 0; i < n; i++){
		//count all elements < a[i]
		count = 0;
		j = 0;
		#pragma omp parallel for num_threads(NUM_THREADS) reduction(+:count) private(j) shared(i)
		for (j = 0; j < n; j++) {
			if(a[j]<a[i] ||(a[j]==a[i] && j<i))
				count++;
		}
		//place a[i] at right order
		temp[count] = a[i];
	}
	//this copies the temp results back into the original array
	memcpy(a, temp, n * sizeof(int));
	free(temp);
}



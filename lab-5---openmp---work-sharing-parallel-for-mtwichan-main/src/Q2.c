
/**
 * Starter code for Lab #5 - Q2
 * 
 **/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define NUM_THREADS 4

int main(void){
    int n = 100;
    int i;
    int a[n];
    int b[n];

    a[0] = 0;
    b[0] = 0;

    for (i=0; i<n; i++) {
    	a[i] = a[i-1] + i;
    }

	#pragma omp parallel num_threads(NUM_THREADS) shared(b) private(i)
    {
		#pragma omp for schedule(static, NUM_THREADS)
    	for (i=0; i<n; i++) {
    		// use triangular number formula
			b[i] = ((i * i) + i) / 2;
		}
    }

    // verify that values are the same
    for (i=1; i<n; i++) {
    	if(a[i] != b[i]) {
			printf("Error at index: %d, a=%d, b=%d \n", i, a[i], b[i]);
    	}
    }


}

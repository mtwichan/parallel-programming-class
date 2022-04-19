
/**
 * Starter code for Lab #5 - Q3
 * 
 * Review the @todo and complete.s
 * 
 * To compile from cmdline:  gcc Q3.c my_rand.c -o Q3.a -fopenmp 
 * 
 **/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

/** added include for random generator */
#include "my_rand.h"

#define NUM_THREADS 4
//
//int main(void){
//    double pi_estimate;
//
//	long long int number_in_circle = 0;
//
//	/** @todo correctly declare and initialize number_of_tosses and set it to a reasonable number of flips*/
//	int number_of_tosses = 1000000;
//
//	/** @todo correctly declare toss, x, y, distance_squared */
//	double distance_squared = 0.0;
//	int toss = 0;
//	double x = 0.0;
//	double y = 0.0;
//	unsigned seed_x = time(NULL);
//	unsigned seed_y = time(NULL) + 987654;
//
//	#pragma omp parallel for num_threads(NUM_THREADS) reduction(+:number_in_circle) private(toss, distance_squared)
//	for (toss = 0; toss < number_of_tosses; toss++) {
//		/** @todo x = random double between -1 and 1; */
//		x = ((my_drand(&seed_x)  - 0.0) * (2.0) / (1.0)) - 1.0;
//
//		/** @todo y = random double between -1 and 1; */
//		y = ((my_drand(&seed_y)  - 0.0) * (2.0) / (1.0)) - 1.0;
//
//		distance_squared = x * x + y * y;
//		if (distance_squared <= 1)
//			number_in_circle++;
//	}
//
//	pi_estimate = 4.0 * number_in_circle / ((double) number_of_tosses);
//
//	printf("Estimated pi: %e\n", pi_estimate);
//
//	return 0;
//
//}

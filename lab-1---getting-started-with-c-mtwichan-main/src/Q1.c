/*
 ============================================================================
 Name        : Q1.c
 Author      : Matthew Chan (58909152)
 Description : Question 1, Lab 1 (L1D)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	// Init variables
	const int ARRAY_SIZE = 4;
	int count = 0;
	double avg = 0;
	int inputValues[ARRAY_SIZE];

	// Input values
	printf("Enter 4 integers separated by spaces: ");
	fflush(stdout);

	// Read user inputs
	scanf("%d %d %d %d", &inputValues[0], &inputValues[1], &inputValues[2], &inputValues[3]);

	// Calculate average
	avg = (double) (inputValues[0] + inputValues[1] + inputValues[2] + inputValues[3]) / ARRAY_SIZE;

	// Check for values above average
	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (inputValues[i] > avg) {
			count++;
		}
	}

	printf("There is %d entries above the average (%0.1f)", count, avg);

	return EXIT_SUCCESS;
}

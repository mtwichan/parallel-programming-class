/*
 ============================================================================
 Name        : q4.c
 Author      : Matthew Chan
 Description : Lab 5 - q4 code

Results:

Threads 2:
Finished image processing in 295.0 ms.

Threads 4:
Finished image processing in 245.0 ms.

Threads 8:
Finished image processing in 241.0 ms.

Threads 16:
Finished image processing in 211.0 ms.
 ============================================================================
 */


/**************************************************************
*
* The program reads a BMP image file and creates a new
* image that is the negative or desaturated of the input file.
*
* @todo use the parallel for construct to parallelize
*
***************************************************************/

#include "qdbmp.h"
#include <stdio.h>
#include <omp.h>

typedef enum {desaturate, negative} ImgProcessing ;
#define NUM_THREADS 16

/* Creates a negative image of the input bitmap file */
int main() {
	const char* inFile = "./src/Q4/okanagan.bmp";
	const char* outFile = "./src/Q4/okanagan_processed.bmp";
	const ImgProcessing processingType = desaturate; //or negative

	UCHAR r, g, b;
	UINT width, height;
	UINT x, y;
	BMP* bmp;

	/* Read an image file */
	bmp = BMP_ReadFile(inFile);
	BMP_CHECK_ERROR(stdout, -1);

	/* Get image's dimensions */
	width = BMP_GetWidth(bmp);
	height = BMP_GetHeight(bmp);

	double t = omp_get_wtime();

	/* Iterate through all the image's pixels */
	#pragma omp parallel for num_threads(NUM_THREADS) collapse(2) private(x, y, r, g, b)
	for (x = 0; x < width; ++x) {
		for (y = 0; y < height; ++y) {
			/* Get pixel's RGB values */
			BMP_GetPixelRGB(bmp, x, y, &r, &g, &b);

			/* Write new RGB values */
			if(processingType == negative)
				BMP_SetPixelRGB(bmp, x, y, 255 - r, 255 - g, 255 - b);
			else if(processingType == desaturate){
				UCHAR gray = r * 0.3 + g * 0.59 + b * 0.11;
				BMP_SetPixelRGB(bmp, x, y, gray, gray, gray);
			}
		}
	}
	/* calculate and print processing time*/
	t = 1000 * (omp_get_wtime() - t);
	printf("Finished image processing in %.1f ms.", t);

	/* Save result */
	BMP_WriteFile(bmp, outFile);
	BMP_CHECK_ERROR(stdout, -2);

	/* Free all memory allocated for the image */
	BMP_Free(bmp);

	return 0;
}

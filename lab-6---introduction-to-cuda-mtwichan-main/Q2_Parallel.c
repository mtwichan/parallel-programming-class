%%cu

#include "cuda_runtime.h"
#include <stdio.h>
#include <stdlib.h>

__global__ void assignArray(double* A, int N) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i < N) {
        A[i] = (double) (i);
    }
}

int main(void) {
    const int N = 10000000;
    float time = 0;
    int i = 0, idx = 0;
    int nBytes = N * sizeof(double);
    int nthreads = 1024;
    int nblocks = (N - 1) / nthreads + 1;

    cudaEvent_t start, stop;
    cudaEventCreate(&start);
    cudaEventCreate(&stop);

    double* A = (double*) malloc(nBytes);  
    double* d_A = NULL;
  
    cudaMalloc(&d_A, nBytes);
    cudaMemcpy(d_A, A, nBytes, cudaMemcpyHostToDevice);

    cudaEventRecord(start);
    assignArray <<<nblocks, nthreads>>> (d_A, N);
    cudaEventRecord(stop);
    cudaEventSynchronize(stop);

    cudaMemcpy(A, d_A, nBytes, cudaMemcpyDeviceToHost);
    cudaEventElapsedTime(&time, start, stop);
    printf("Execution Time: %fs\n", time / 1000.0);

    for (i = 0; i < 5; i++) {
        printf("a[%d]: %.7f\n", i, A[i]);
    }

    for (i = 5; i > 0; i--) {
        idx = N - i;
        printf("a[%d]: %.7f\n", idx, A[idx]);
    } 

    free(A);
    cudaFree(d_A);  
}
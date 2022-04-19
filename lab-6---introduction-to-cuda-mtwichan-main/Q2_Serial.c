%%cu
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    const int n = 10000000;
    int i = 0;
    int idx = 0;
    time_t start_t, end_t;

    double *a = (double*) malloc(sizeof(double) * n);
    
    start_t = clock();
    for (i = 0; i < n; i++) {
        a[i] = (double)i / n;   
    }
    end_t = clock();
    
    printf("Execution Time: %fs\n", ((double)(end_t - start_t) / CLOCKS_PER_SEC));
    for (i = 0; i < 5; i++) {
        printf("a[%d]: %.7f\n", i, a[i]);
    }

    for (i = 5; i > 0; i--) {
        idx = n - i;
        printf("a[%d]: %.7f\n", idx, a[idx]);
    }   
}
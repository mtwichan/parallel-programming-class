/*
 ============================================================================
 Name        : Q4.c
 Author      : Matthew Chan (58909152)
 Description : Question 4, Lab 2 (L1D)

Threads: 2, Size: 1K:

 Created new thread (9771256) ...

 Created new thread (9781672) ...
All threads are done!
Total time: 0.000001 ms
Sums all good!

Threads: 2, Size: 1M:

 Created new thread (250681592) ...

 Created new thread (250692008) ...
All threads are done!
Total time: 0.000034 ms
Sums all good!

Threads: 4, Size: 1K:

 Created new thread (10164472) ...

 Created new thread (10174888) ...

 Created new thread (10175616) ...

 Created new thread (10176344) ...
All threads are done!
Total time: 0.000001 ms
Sums all good!

Threads: 4, Size: 1M:

 Created new thread (487594232) ...

 Created new thread (487604648) ...

 Created new thread (487605376) ...

 Created new thread (487606104) ...
All threads are done!
Total time: 0.000040 ms
Sums all good!

Threads: 8, Size: 1K:

 Created new thread (7739640) ...

 Created new thread (7750056) ...

 Created new thread (7750784) ...

 Created new thread (7751512) ...

 Created new thread (7752240) ...

 Created new thread (7752968) ...

 Created new thread (7754248) ...

 Created new thread (7753704) ...
All threads are done!
Total time: 0.000001 ms
Sums all good!


Threads: 8, Size: 1M:

 Created new thread (967710968) ...

 Created new thread (967721384) ...

 Created new thread (967722112) ...

 Created new thread (967722840) ...

 Created new thread (967723568) ...

 Created new thread (967724296) ...

 Created new thread (967725576) ...

 Created new thread (967705776) ...
All threads are done!
Total time: 0.000059 ms
Sums all good!


Threads: 16, Size: 1K:


 Created new thread (6691064) ...

 Created new thread (6701480) ...

 Created new thread (6702208) ...

 Created new thread (6702936) ...

 Created new thread (6704208) ...

 Created new thread (6704936) ...

 Created new thread (6705128) ...

 Created new thread (6691248) ...

 Created new thread (6691432) ...

 Created new thread (6705856) ...

 Created new thread (6706040) ...

 Created new thread (6706944) ...

 Created new thread (6707128) ...

 Created new thread (6704392) ...

 Created new thread (6704576) ...

 Created new thread (6708576) ...
All threads are done!
Total time: 0.000001 ms
Sums all good!

Threads: 16, Size: 1M:

 Created new thread (1927878904) ...

 Created new thread (1927889320) ...

 Created new thread (1927890048) ...

 Created new thread (1927890776) ...

 Created new thread (1927891504) ...

 Created new thread (1927892232) ...

 Created new thread (1927893512) ...

 Created new thread (1927879088) ...

 Created new thread (1927879272) ...

 Created new thread (1927892416) ...

 Created new thread (1927892600) ...

 Created new thread (1927892784) ...

 Created new thread (1927890232) ...

 Created new thread (1927890416) ...

 Created new thread (1927873712) ...

 Created new thread (1927896416) ...
All threads are done!
Total time: 0.000122 ms
Sums all good!


 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

//This defines the number of threads that will be used for the problem
/** @todo adjust this ! */
#define NUM_THREADS 2

// The array size must be a multiple of the number of thread (for this example)
// otherwise bad things will happen (ie one thread attempting to access data
// outside of the bounds of the array)
#define VALUE 1000  /** @todo adjust this value to increase number of elements */
#define ARRAY_SIZE (NUM_THREADS * VALUE)

//this is the length of the slice (ARRAY_SIZE/NUM_THREADS)
int length;

volatile int A[ARRAY_SIZE];
volatile int B[ARRAY_SIZE];
volatile int C[ARRAY_SIZE];

/**
 * Function to run as a pthread.  To properly pass args into a function
 * with pthreads, we need to create a struct for each thread and then
 * pass in a pointer to it.
 *
 * In this case, to keep things easier (but not clean), A, B and C have
 * been declared as globals along with a fixed slice (sub-array size).
 * The value that is then passed in is the offet.
 **/
void* add_vector(void* data)
{
    int offset = *((int *)data);  //cast the data as an integer (offset into array)

    // this will work through only a portion of the array
    // Each thread, will process only a part of the global array
    // and it's starting position will be controlled by the offset.
    // In this case with POSIX threads, we need to control
    // the offset when the thread is created.
    for (int i = 0 ; i < length; i++)
    {
	    /** @todo Complete the programming statement adding c = a + b
         (hint: you will need to use i and the offset -> think about how
         the data is being sliced ).  You might want to experiment
         with only two threads and a smaller array to make sure it works (+2 marks)
         */
    	C[i + offset] = A[i + offset] + B[i + offset];
    }
    pthread_exit(NULL);			// terminate the thread
    return NULL;
}

/* like any C program, program's execution begins in main */
int main(int argc, char* argv[])
{
    int rc[NUM_THREADS];
    int start_pos[NUM_THREADS];
    double total_time;
    time_t start, end;

    // for a given array size, generated random values for
    // each location of A and B (+4)
    // Create a seed for random time
    srand(time(0));
    for (int i = 0; i < ARRAY_SIZE; i ++)
    {
    	/** @todo Initial A with random values */
    	A[i] = rand();

    	/** @todo Initial B with random values */
    	B[i] = rand();

    }
    pthread_t  t[NUM_THREADS]; // thread's ID (just an integer)

    // This is the slice!  Just determining based on the
    // number of threads, how many times it can be sub-arrayed
    // IMPORTANT: The array size must be a multiple of the number
    // of threads or it will break!!
    length = ARRAY_SIZE / NUM_THREADS;

    for (int i = 0; i < NUM_THREADS; i++)
    {
    	// Calculate the starting position in the array for each thread
	// based on the length of each slice (sub-array) as calculated
	// above.  For the first thread, it will start at index 0, the next
	// thread will then start of i * length (if the length of the slice is
	// 10, it would then start at index 10 and process indexes 10-19....
	// With POSIX threads, we only have access to the thread id, which
	// is just a handle to the thread and not a index (or count value); so
	// it is up to use to enumerate them for slicing.
    start_pos[i] = i * length;

    //This launches the threads!
    // Add timing information to record the time from start of the thread, until
    // all threads have returned (after the join).  Print out the timing at the end.
    // (+4 - timing + printout out resutls)
	/** @todo - timing starts here! */
    start = clock();
    rc[i] = pthread_create(&(t[i]), NULL, add_vector, (void*)&(start_pos[i]));

	if(rc[i])			// could not create thread
	{
		printf("\n ERROR: return code from pthread_create is %d \n", rc[i]);
		exit(1);
	}
	else
    	{
		printf("\n Created new thread (%d) ...\n",t[i]);
    	}
    }

    //now wait for the threads to end...
    for (int i =0; i < NUM_THREADS; i++)
    {
	    pthread_join(t[i], NULL);
    }
    /** @todo Timing stops here!*/
    end = clock();
    // Calculate time
    total_time = ((double)(end - start) / CLOCKS_PER_SEC) / 1000;

    fflush(stdout);
    printf("All threads are done!\n");
    printf("Total time: %f ms \n", total_time);

    //check results
    char bad = 0;

    for (int i = 0; i < ARRAY_SIZE; i ++)
    {
	    if (A[i] + B[i] != C[i])
	    {
	    	    printf("Error at %d\n",i);
		    bad |= 1;
	    }
    }
    if (bad)
    {
	    printf("Sums failed\n");
    }
    else
    {
	    printf("Sums all good!\n");
    }

    exit(0);
}

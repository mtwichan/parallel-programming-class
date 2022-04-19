/**
* Starter code for lab 2 - Q4
* @todo Please read the comments in the code to understand what needs to be done
* To compile on command line:  gcc Q4.c -o 4.exe -lpthread
**/
#include <stdio.h>       
#include <stdlib.h>
#include <pthread.h>     

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
    } 
    pthread_exit(NULL);			// terminate the thread 
	
}

/* like any C program, program's execution begins in main */
int main(int argc, char* argv[])
{
    int rc[NUM_THREADS];         	
    int start_pos[NUM_THREADS];

    // for a given array size, generated random values for 
    // each location of A and B (+4)
    for (int i = 0; i < ARRAY_SIZE; i ++)
    {
    	/** @todo Initial A with random values */
	   	/** @todo Initial B with random values */
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
    rc[i] = pthread_create(&(t[i]), NULL, add_vector, (void *)&(start_pos[i])); 

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

    printf("All threads are done!");

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

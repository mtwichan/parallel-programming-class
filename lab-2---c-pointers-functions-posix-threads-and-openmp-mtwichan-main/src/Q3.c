/**
* Starter code for lab 2 - Q3
* To compile on command line:  gcc Q3.c -o 3.exe -lpthread
**/
#include <stdio.h>       
#include <stdlib.h>
#include <pthread.h>     

//This defines the number of threads that will be used for the problem
#define NUM_THREADS 4

/**
 * Function to run as a pthread
 **/
void* print_hello(void* data)
{
    char *my_data = (char* )data;  //cast the data as char array     	
    
    //print out message and thread id	
    printf("Hello! - got %s from thread #%d \n", my_data, (int)pthread_self());
    pthread_exit(NULL);			// terminate the thread 
	
}

/* like any C program, program's execution begins in main */
int main(int argc, char* argv[])
{
    int rc[NUM_THREADS];         	
    pthread_t  t[NUM_THREADS]; // thread's ID (just an integer)     
    
    for (int i = 0; i < NUM_THREADS; i++)
    {
    	/* create a new thread that will execute 'print_hello' */
      	rc[i] = pthread_create((t[i]), NULL, print_hello, (void*)("hello!")); 

    	if(rc[i])			// could not create thread 
    	{
        	printf("\n ERROR: return code from pthread_create is %d \n", rc[i]);
	        exit(1);
    	}
	else
    	{
		printf("\n Created new thread (%d) ... \n", t[i]);	
	}
    }
    //now wait for the threads to end...
    for (int i =0; i < NUM_THREADS; i++)
    {
	    pthread_join(t[i], NULL);
    }
    printf("All threads are done!");
    exit(0);
}

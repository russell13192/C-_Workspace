#include <iostream>
#include "Complex.h"


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define NUM_THREADS 5

using namespace std;
void *perform_work(void *argument)
{
    int passed_in_value;

    passed_in_value = *((int *) argument);
    printf("Hello World! It's me, thread with argument %d!\n", passed_in_value);

    /* optionally: insert more useful stuff here */

    return NULL;
}

int main(void)
{
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int result_code, index;

    for (index = 0; index < NUM_THREADS; ++index) {
        thread_args[index] = index;
        printf("In main: creating thread %d\n", index);
        result_code = pthread_create(&threads[index], NULL, perform_work, (void *) &thread_args[index]);
        assert(0 == result_code);
    }


    for (index = 0; index < NUM_THREADS; ++index) {
        // block until thread 'index' completes
        result_code = pthread_join(threads[index], NULL);
        printf("In main: thread %d has completed\n", index);
        assert(0 == result_code);
    }

    printf("In main: All threads completed successfully\n");
    cout << "Creating Complex Class" << endl;
    Complex c1(2, 3); 
    Complex c2(c1);

    Complex c3 = c2;


    // cout << "c2: " << c2.getReal() << "<" << c2.getImg() <<">" << endl;
    cout << c2 << ": " << c3 << endl;
    return 0;
    exit(EXIT_SUCCESS);
}




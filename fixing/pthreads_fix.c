#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10
#define INCREMENTS 100000

int counter = 0;

// Step 1: Initialize a mutex to protect the shared counter
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

// Goal: Each thread increments the global counter 100,000 times.
// Total expected counter: 1,000,000
void* increment_counter(void* arg) {
    for (int i = 0; i < INCREMENTS; i++) {
        // Step 2: Lock the mutex before accessing the shared resource
        pthread_mutex_lock(&lock);
        counter++;
        // Step 3: Unlock the mutex immediately after the update
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];

    printf("Starting %d threads to increment counter...\n", NUM_THREADS);

    // Create the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, increment_counter, NULL) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }

    // Step 4: Wait for all threads to finish (pthread_join)
    // Without this, the main thread will exit before the others are done!
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final Counter: %d\n", counter);
    printf("Expected Counter: %d\n", NUM_THREADS * INCREMENTS);

    // Clean up the mutex
    pthread_mutex_destroy(&lock);

    return 0;
}

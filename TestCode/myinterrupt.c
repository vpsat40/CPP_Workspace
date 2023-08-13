/**
 * @file myinterrupt.c
 * @author your name (you@domain.com)
 * @brief 
 * A synchronous interrupt reads a signed 16-bit sample. 
 * Write code in C that executes in this interrupt to efficiently evaluate the sum of the last 12 samples.
 * You may assume
 *      - short is 16 bit
 *      - long is 32 bit
 * 
 * @version 0.1
 * @date 2023-07-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */



#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>


#define SAMPLE_RATE_MICROSECONDS 100000  // Sample rate: 10000 microseconds (100 milliseconds)
#define BUFFER_SIZE 12

// Declare a buffer structure
typedef struct 
{
    short int samples[BUFFER_SIZE]; // place to hold last 12 buffer samples
    long int sum;  // place to hold the sum
    int index;
} Buffer;

int running = 1;

void close_handler(int sig)
{
    running = 0;
}

/**
 * @brief Function to initialize empty buffer. 
 * After every 12 samples the buffer is cleared.
 */
void initBuffer(Buffer* buffer) 
{
    buffer->sum = 0;
    buffer->index = 0;
    for (int i = 0; i < BUFFER_SIZE; i++) 
    {
        buffer->samples[i] = 0;
    }
    printf("---------Buffer initialized--------------\n");
}

/**
 * @brief Function to update new sample into existing buffer. 
 */
void updateBuffer(Buffer* buffer, short int sample) 
{
    // Update Sum and sample in array
    buffer->sum += sample;
    buffer->samples[buffer->index] = sample;

    // Increment the buffer index 
    buffer->index = (buffer->index + 1) % BUFFER_SIZE;
}

/**
 * @brief Function to get sum of the last 12 samples
 * 
 */
int getSum(const Buffer* buffer) 
{
    return buffer->sum;
}

/**
 * @brief Handler for ualarm signals
 * 
 */
void interruptHandler(int signal) 
{
    // Generate random signed 16-bit sample
    // This sample can be assumed as the sample read from memory/register
    short int newSample = (rand() % 65536) - 10000;
    printf("New sample = %d\n", newSample);
    
    // Instantiate static buffer object. This will retain values across multiple handler calls.
    static Buffer myBuffer;

    // Initialize the buffer on the first interrupt call
    if (myBuffer.index == 0) 
        initBuffer(&myBuffer);
 
    updateBuffer(&myBuffer, newSample);
    long int sum = getSum(&myBuffer);

    // Process the sum as needed
    printf("Sum of last 12 Samples: %ld\n\n", sum);    
}

int main() 
{
    // Set up signals and their signal handlers 
    signal(SIGALRM, interruptHandler);
    signal(SIGINT, close_handler);
    signal(SIGTERM, close_handler);

    // Set up the periodic signal using ualarm
    ualarm(SAMPLE_RATE_MICROSECONDS, SAMPLE_RATE_MICROSECONDS);

    // Infinite loop. Keep reading from the synchronous interrupt until terminated.
    while (running) 
    {
    }

    return 0;
}
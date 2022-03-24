#include "../../include/core/bbuffer.h"

/**
 * @brief check header file for instruction
 * 
 */
typedef struct BNDBUF 
{
    int input;
    int output;
    int* data;
    int count;
    SEM* bufferFull;
    SEM* bufferEmpty;
} BNDBUF;

/**
 * @brief check header file for instruction
 * 
 */
BNDBUF *bb_init(unsigned int size) 
{
    BNDBUF *buffer = malloc(sizeof(BNDBUF));
    buffer->input = 0;
    buffer->output = 0;
    buffer->count = 0;
    buffer->data = malloc(sizeof(int)*size);
    buffer->bufferFull = sem_init(0);

    if(!(buffer->bufferFull)){
        free(buffer->data);
        return NULL;
    }

    buffer->bufferEmpty = sem_init(size);

    if(!(buffer->bufferEmpty)){
        free(buffer->data);
        sem_del(buffer->bufferEmpty);
        return NULL;
    }
    return buffer;
}

/**
 * @brief check header file for instruction
 * 
 */
void bb_del(BNDBUF *bb)
{
    free(bb->data);
    sem_del(bb->bufferFull);
    sem_del(bb->bufferEmpty);
}

/**
 * @brief check header file for instruction
 * 
 */
int  bb_get(BNDBUF *bb)
{
    P(bb->bufferFull);
    int last = bb->count-1;
    int data = bb->data[last];
    bb->count = bb->count - 1;
    V(bb->bufferEmpty);

    return data;
}

/**
 * @brief check header file for instruction
 * 
 */
void bb_add(BNDBUF *bb, int fd)
{
    P(bb->bufferEmpty);
    bb->data[bb->count] = fd;
    bb->count++;
    V(bb->bufferFull);
}
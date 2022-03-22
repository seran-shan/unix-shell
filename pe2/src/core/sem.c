#include "../../include/core/sem.h"

typedef struct SEM
{
    int count;
    pthread_mutex_t lock;
    pthread_cond_t cond;
} SEM;


SEM *sem_init(int initVal) 
{
    SEM* sem = malloc(sizeof(struct SEM));

    if (!sem) return NULL;
    sem->count = initVal;
    
    errno = pthread_mutex_init(&sem->lock, NULL);
    if (!errno) 
    {
        pthread_mutex_destroy(&sem->lock);
        free(sem);
        return NULL;
    }


    errno = pthread_cond_init(&sem->cond, NULL);
    if (!errno) 
    {
        pthread_cond_destroy(&sem->cond);
        free(sem);
        return NULL;
    }

    return sem;
}

int sem_del(SEM *sem) 
{
    errno = pthread_mutex_destroy(&sem->lock);
    if (!errno)
    {
        errno = pthread_cond_destroy(&sem->cond);
        if (!errno)
        {
            free(sem);
            return 0;
        }
        
    }
    return errno;
}

void P(SEM *sem)
{
    pthread_mutex_lock(&sem->lock);

    while (sem->count == 0)
    {
        pthread_cond_wait(&sem->cond, &sem->lock);
    }

    sem->count = sem->count - 1;

    if (sem->count > 0)
    {
        pthread_cond_signal(&sem->cond);
    }
    
    pthread_mutex_unlock(&sem->lock);
}

void V(SEM *sem)
{
    pthread_mutex_lock(&sem->lock);
    sem->count++;

    if (sem->count == 1) {
        pthread_cond_signal(&sem->cond);
    }
    
    pthread_mutex_unlock(&sem->lock);
}
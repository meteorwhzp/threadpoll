#include "threadpool.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void* myTask(void* arg)
{
    printf("thread %d is working on task%d\n", (int)pthread_self(), *(int*)arg);
    sleep(1);
    free(arg);
    return NULL;
}

int main(void)
{
    threadpool_t pool;
    threadpool_init(&pool, 3);
    int i;
    for(i = 0; i < 10; i++){
        int *arg = malloc(sizeof(int));
        *arg = i;
        threadpool_add_task(&pool, myTask, arg);
        }

    threadpool_destroy(&pool);
    return 0;
}


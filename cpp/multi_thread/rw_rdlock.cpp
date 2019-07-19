#include "pthread.h"
#include <iostream>
#include <unistd.h>
#include <stdio.h>
using namespace std;

pthread_rwlock_t rwlock;
int num = 0;
void *thread_fun1(void* arg)
{
    int err;
    pthread_rwlock_rdlock(&rwlock);
    printf("thread 1 print num %d\n", num);
    sleep(5);
    printf("Thread 1 will over\n");
    pthread_rwlock_unlock(&rwlock);
    return (void *) 1;
}
void *thread_fun2(void *arg)
{
    int err;
    pthread_rwlock_rdlock(&rwlock);
    printf("thread 2 print num %d\n", num);
    sleep(5);
    printf("Thread 2 will over \n");
    pthread_rwlock_unlock(&rwlock);
    return (void *)1;
}

int main()
{
    printf("g++ -lpthread --std=c++11");

    pthread_t tid1, tid2;
    int err;
    err = pthread_rwlock_init(&rwlock, NULL);
    if(err)
    {
        printf("init rwlock failed\n");
        return -1;
    }
    err = pthread_create(&tid1, NULL, thread_fun1, NULL);
    if(err)
    {
        printf("create new thread1 failed\n");
        return -1;
    }
    err = pthread_create(&tid2, NULL, thread_fun2, NULL);
    if(err)
    {
        printf("create new thread2 failed\n");
        return -1;
    }
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_rwlock_destroy(&rwlock);
    return 0;
}

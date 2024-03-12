#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX 256
char *buffer;
sem_t empty;     // 定义同步信号量empty
sem_t full;      // 定义同步信号量full
sem_t mutex;     // 定义互斥信号量mutex
void *producer() // 生产者
{
    while (1)
    {
        sem_wait(&empty); // empty的P操作
        sem_wait(&mutex); // mutex的P操作
        int tem;
        sem_getvalue(&full, &tem);
        printf("生产一个产品ing， 之前总共%d,这是第%d个\n", tem, tem + 1);
        usleep(100000);
        sem_post(&mutex); // mutex的V操作
        sem_post(&full);
    } // full的V操作
}
void *consumer() // 消费者
{
    while (1)
    {
        sem_wait(&full);  // full的P操作
        sem_wait(&mutex); // mutex的P操作
        int tem;
        sem_getvalue(&full, &tem);
        printf("消费一个产品ing，总共%d,这是第%d个\n", tem + 1, tem + 1);
        usleep(100000);
        sem_post(&mutex); // mutex的V操作
        sem_post(&empty); // empty的V操作
    }
}
int main()
{
    pthread_t id_producer;
    pthread_t id_consumer;
    int ret;
    sem_init(&empty, 0, 6);                                   // 设置empty到初值为6
    sem_init(&full, 0, 0);                                    // 设置full到初值为0
    sem_init(&mutex, 0, 1);                                   // 设置mutex到初值为1
    ret = pthread_create(&id_producer, NULL, producer, NULL); // 创建生产者线程
    ret = pthread_create(&id_consumer, NULL, consumer, NULL); // 创建消费者线程
    pthread_join(id_producer, NULL);                          // 等待生产者线程结束
    pthread_join(id_consumer, NULL);                          // 等待消费者线程结束
    sem_destroy(&empty);                                      // 删除信号量
    sem_destroy(&full);
    sem_destroy(&mutex);
    printf("The End...\n");
}
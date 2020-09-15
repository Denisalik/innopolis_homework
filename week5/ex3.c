#include <stdio.h>
#include <pthread.h>
#include <time.h>
#define N 10
int buffer[N];
int count = 0;
time_t start;
int i=0;
pthread_mutex_t mutex;
pthread_t thread_producer, thread_consumer;
pthread_cond_t conditionalconsumer, conditionalproducer;

void* consumer(){
for(;;){
pthread_mutex_lock(&mutex);//locking mutex
if(count==0)pthread_cond_wait(&conditionalconsumer, &mutex);//perform a blocking wait for signal from producer
buffer[count]=0;//do something with a buffer 1=producer, 0=consumer
count = count - 1;
printf("count from consumer is %d\n", count);
pthread_cond_signal(&conditionalproducer);//signal producer to wake up
pthread_mutex_unlock(&mutex);//unlocking mutex
}
}

void* producer(){
for(;;){
pthread_mutex_lock(&mutex);//locking mutex
if(N == count) pthread_cond_wait(&conditionalproducer, &mutex);//perform a blocking wait for signal from consumer
buffer[count]=1;//do something with a buffer 1=producer, 0=consumer
count = count+ 1;
printf("count from producer is %d\n", count);
if((int)time(NULL)-(int)start > 60*i){
printf("Producer is printing:\"passed %d seconds\"\n", (int)time(NULL)-(int)start);i++;
}
pthread_cond_signal(&conditionalconsumer);//signal consumer to wake up
pthread_mutex_unlock(&mutex);//unlocking mutex
}
}
int main(){
start = time(NULL);
pthread_mutex_init(&mutex, NULL);
pthread_cond_init(&conditionalproducer, NULL);
pthread_cond_init(&conditionalconsumer, NULL);
pthread_create(&thread_producer, NULL, &producer, NULL);
pthread_create(&thread_consumer, NULL, &consumer, NULL);
pthread_join(thread_producer, NULL);
pthread_join(thread_consumer, NULL);
pthread_cond_destroy(&conditionalconsumer);
pthread_cond_destroy(&conditionalproducer);
pthread_mutex_destroy(&mutex);
return 0;
}

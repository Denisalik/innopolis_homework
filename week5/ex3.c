#include <stdio.h>
#include <pthread.h>
#include <time.h>
#define N 10
int buffer[N];
int count = 0;
time_t start;
int i=0;
pthread_mutex_t mutex;//declaring all variables
pthread_t thread_producer, thread_consumer;
pthread_cond_t conditionalconsumer, conditionalproducer;

void* consumer(time_t start){
for(;;){
pthread_mutex_lock(&mutex);//locking mutex
if(count==0)pthread_cond_wait(&conditionalconsumer, &mutex);//sleep until producer signal to consumer
buffer[count]=0;//do something with a buffer 1=producer, 0=consumer
count = count - 1;
if((int)time(NULL)-(int)start > 3*i){
printf("count from consumer is %d\n", count);
printf("Consumer is printing:\"passed %d seconds\"\n", (int)time(NULL)-(int)start);i++;
}
pthread_cond_signal(&conditionalproducer);//signal producer to wake up
pthread_mutex_unlock(&mutex);//unlocking mutex
}
}

void* producer(time_t start){
for(;;){
pthread_mutex_lock(&mutex);//locking mutex
if(N == count) pthread_cond_wait(&conditionalproducer, &mutex);//sleep untial consumer wake producer
buffer[count]=1;//do something with a buffer 1=producer, 0=consumer
count = count+ 1;
if((int)time(NULL)-(int)start > 3*i){
printf("count from producer is %d\n", count);
printf("Producer is printing:\"passed %d seconds\"\n", (int)time(NULL)-(int)start);i++;
}
pthread_cond_signal(&conditionalconsumer);//signal consumer to wake up
pthread_mutex_unlock(&mutex);//unlocking mutex
}
}
int main(){
start = time(NULL);
pthread_mutex_init(&mutex, NULL);//initialization of all conditional variables and mutex 
pthread_cond_init(&conditionalproducer, NULL);
pthread_cond_init(&conditionalconsumer, NULL);
pthread_create(&thread_producer, NULL, &producer, start);//creating threads
pthread_create(&thread_consumer, NULL, &consumer, start);
pthread_join(thread_producer, NULL);//waiting for 2 threads until they finish
pthread_join(thread_consumer, NULL);
pthread_cond_destroy(&conditionalconsumer);
pthread_cond_destroy(&conditionalproducer);
pthread_mutex_destroy(&mutex);
return 0;
}

#include<pthread.h>
#include<stdio.h>
#define N 5
pthread_t tid[N];

void* print(int i){
pthread_t id = pthread_self();
printf("thread number %d with id %d is working\n", i, id);
pthread_exit(NULL);
return NULL;
}
// if there is no joins then firstly program create threads and after that they can start work even before creation of all threads is not finished. So order will be chaotic.
//with joins it will be sequentially creating -> working -> exiting again and again
int main(){
int i, current;
for(i=0;i<N;i++){
printf("creating thread number %d\n", i);
current = pthread_create(&(tid[i]), NULL, &print, i);
pthread_join(tid[i], NULL);

}
return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>
int main(){
	int i;
	for(i=0;i<10;i++){
		int* ptr = malloc(10*1024*1024);
		memset(ptr,0,10*1024*1024);
		struct rusage usage;
		getrusage(RUSAGE_SELF,&usage);
		printf("memory = %ld\n", usage.ru_maxrss);//it will print around 11K and then increase every second by around 10K
		sleep(1);
	}
}

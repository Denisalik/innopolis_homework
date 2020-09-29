#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
void* myRealloc(void* ptr, size_t size){
	if(ptr==NULL)return malloc(size);
	if(size==0){
		free(ptr);
		return;
	}
	void* ptrnew = malloc(size);
	size_t oldsize = malloc_usable_size(ptr);
	if(size>=oldsize){
		memcpy(ptrnew,ptr,oldsize);
	}
	else {
		memcpy(ptrnew,ptr,size);
	}
	free(ptr);
	return ptrnew;
}

int main(){
	int* arr = malloc(sizeof(int)*5);
	int i;
	for(i=0;i<5;i++){
		arr[i]=i;
		printf("%d\n",arr[i]);	
	}
	arr = myRealloc(arr,2*sizeof(int));
	printf("After reallocation:\n");
	for(i=0;i<5;i++)printf("%d\n",arr[i]);
	return 0;
}

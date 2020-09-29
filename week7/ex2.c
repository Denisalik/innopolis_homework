#include <stdio.h>
#include <stdlib.h>
int main(){
	int N,i;
	scanf("%d",&N);
	int* arr = malloc(sizeof(int)*N);
	for(i = 0;i < N;i++){
		arr[i] = i;
		printf("%d\n",arr[i]);
	}
	free(arr);
}

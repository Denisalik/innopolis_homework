#include <stdlib.h>
bubble_sort(int* arr, int n){
	int i,j;
	for(i = 0;i<n-1;i++){
		for(j = 0;j<n-1-i;j++){
			if(arr[j]>arr[j+1]){
				int c = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = c;
			}
		}
	}
}
int main(){
	int n = 5,i;
	int* arr = malloc(sizeof(int)*n);
	for(i = 0; i<n;i++)arr[i] = n-i;
	for(i = 0; i<n;i++)printf("%d ",arr[i]);
	printf("\n");
	bubble_sort(arr,n);
	for(i = 0; i<n;i++)printf("%d ",arr[i]);
}

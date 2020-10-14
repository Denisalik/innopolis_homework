#include <stdio.h>
#include <stdlib.h>
struct process{
	unsigned int time;
	int id;
	int rbit;
};
void update_age(struct process arr[], int n){
	int i;
	for(i=0;i<n;i++){
		arr[i].time=arr[i].time/2;//place all bits righter
		arr[i].time+=arr[i].rbit*pow(2,15);//adding to the leftmost bit r bit
		arr[i].rbit = 0;
		//32768 because counter is 16 bit, so if the first bit is 1(hit), then 2^(16-1)=32768
		//in general if counter is q bit, then we need to write arr[j].time+=pow(2,q-1);
	}
}
void increment(int a, struct process arr[], int n, int* hit, int* miss){
	int j,i,min=arr[0].time,index=0;
	for(j=0;j<n;j++){
		if(arr[j].id==a){
			arr[j].rbit = 1;
			*hit=*hit+1;//if rbit is is memory then it is hit
			return;
		}
		if(arr[j].time<min){
			min = arr[j].time;
			index = j;
		}
	}
	*miss=*miss+1;//if there is not bit in memory then we need to rewrite page with the minimum of counter and it is miss
	arr[index].id = a;
	arr[index].time = 0;
	arr[index].rbit = 1;
	return;
}
int main(){
	int i,n;
	int hit = 0;
	int miss = 0;
	int a;
	int c;
	FILE* fp = fopen("Lab 09 input.txt", "r");
	printf("specify number of frame pages in memory and clock timer:\n");
	scanf("%d",&n);//n==number of frame pages
	scanf("%d",&c);//c==clock timer
	struct process memory[n];
	for(i = 0;i < n;i++){
		memory[i].time = 0;
		memory[i].id = -1;
		memory[i].rbit = 0;
	}
	int count=0;
	fscanf(fp,"%d",&a);
	increment(a,memory,n,&hit,&miss);
	if(count%c==0)update_age(memory,n);
	count++;
    	while(!feof(fp)){
    		fscanf(fp,"%d",&a);
        	increment(a,memory,n,&hit,&miss);
        	if(count%c==0)update_age(memory,n);
        	count++;
        	//last symbol of file should be integer or last symbol will get read many times insted of 1
    }
    double ratio = (double)hit/(double)miss;
    printf("hits:%d misses:%d hit/miss ratio:%lf",hit,miss,ratio);
    //10page frames and clock timer is 1: hits:10 misses:990 hit/miss ratio:0.010101
    //50page frames and clock timer is 1: hits:19 misses:981 hit/miss ratio:0.019368
    //100page frames and clock timer is 1: hits:19 misses:981 hit/miss ratio:0.019368
    fclose(fp);
}

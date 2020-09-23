#include <stdio.h>
#include <pthread.h>
#include <time.h>
struct process {
int ind;
double arr_time;
double burst_time;
double initial_burst_time;
double wait_time;
double complete;
};


void Robin(struct process(*time)[], int n, double exit, double q){
	int i;//if if are done 0 times to do
	int count=0;
	while(count!=n){
		for(i=0;i<n;i++){
			if((*time)[i].arr_time<=exit && (*time)[i].burst_time!=0){
				if((*time)[i].burst_time> q){
					exit+=q;
					(*time)[i].burst_time-=q;
				}
				else {
					exit+= (*time)[i].burst_time;
					(*time)[i].wait_time = exit - (*time)[i].burst_time;
					(*time)[i].burst_time = 0;
					count++;
					(*time)[i].complete = exit;
				}
			}
		}
	}
} 



int main(){
int i,n;
double quantum;
double a,b,exit=0,tat,wt,avgturn,avgwait,sumwt,sumtat;
struct process time[1000];
scanf("%d",&n);
scanf("%lf",&quantum);
for(i = 0;i<n;i++){
time[i].ind=i;
scanf("%lf%lf",&a,&b);
time[i].arr_time = a;
time[i].burst_time = b;
time[i].initial_burst_time = b;
time[i].wait_time = 0;
time[i].complete = 0;
}
printf("i\tCT\t\tTAT\t\tWT\n");

struct process** pointer = &time;

Robin(pointer, n, exit, quantum);
for(i=0;i<n;i++){
double exit = time[i].complete;

tat = exit - time[i].arr_time;
wt = tat-time[i].initial_burst_time;
sumtat+=tat;
sumwt+=wt;
printf("%d\t%f\t%f\t%f\n",time[i].ind,exit,tat,wt);
}
printf("avgTAT = %f\tavgWT = %f",sumtat/n,sumwt/n);

return 0;
}

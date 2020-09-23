#include <stdio.h>
struct process {
int ind;
double arr_time;
double burst_time;
};
int compare(const struct process* a, const struct process* b) 
{ //comparator between arrivals of 2 processes
    return a->arr_time>b->arr_time?1:-1; 
} 
double max(double a, double b){
	return a>b?a:b;
}
int main(){
int i,n;
double a,b,exit,tat,wt,avgturn,avgwait,sumwt,sumtat;
struct process time[1000];
scanf("%d",&n);//n=number of processes
for(i = 0;i<n;i++){
time[i].ind=i;//saving indeces before sorting
scanf("%lf%lf",&a,&b);
time[i].arr_time = a;
time[i].burst_time = b;
}
qsort(time, n, sizeof(time[0]), compare);
for(i=0;i<n;i++){
	//---
	// ---
	// Considering this two situations, that's why we use max(arrival, exit time of previous process)
	//---
	//       ---
exit = i>0?max(time[i].arr_time, exit)+time[i].burst_time:
time[i].arr_time+time[i].burst_time;//if i=0 first arrived process will start
tat = exit - time[i].arr_time;
wt = tat-time[i].burst_time;
sumtat+=tat;
sumwt+=wt;
printf("i=%d CT=%f TAT=%f WT=%f\n",time[i].ind,exit,tat,wt);
}//it will print index of receiving data before sorting, CT=exit time, TAT=Turnaround time, WT=Waiting time
printf("avgturn = %f avgwait = %f",sumtat/n,sumwt/n);//average turnaround time and average waiting time

return 0;
}

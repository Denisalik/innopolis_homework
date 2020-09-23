#include <stdio.h>
#include <pthread.h>
#include <time.h>
//time_t start = time(NULL);
struct process {
int ind;
double arr_time;
double burst_time;
};
int compare(const struct process* a, const struct process* b) 
{ 
    return a->arr_time>b->arr_time?1:-1; 
} 
double max(double a, double b){
	return a>b?a:b;
}
int main(){
int i,n;
double a,b,exit,tat,wt,avgturn,avgwait,sumwt,sumtat;
struct process time[1000];
scanf("%d",&n);
for(i = 0;i<n;i++){
time[i].ind=i;
scanf("%lf%lf",&a,&b);
time[i].arr_time = a;
time[i].burst_time = b;
}
qsort(time, n, sizeof(time[0]), compare);
for(i=0;i<n;i++){
exit = i>0?max(time[i].arr_time, exit)+time[i].burst_time:
time[i].arr_time+time[i].burst_time;
tat = exit - time[i].arr_time;
wt = tat-time[i].burst_time;
sumtat+=tat;
sumwt+=wt;
printf("i=%d CT=%f TAT=%f WT=%f\n",time[i].ind,exit,tat,wt);
}
printf("avgturn = %f avgwait = %f",sumtat/n,sumwt/n);

return 0;
}

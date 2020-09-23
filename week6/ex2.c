#include <stdio.h>
struct process {
int ind;
double arr_time;
double burst_time;
int passed;
};
int compare(const struct process* a, const struct process* b) 
{ 
    return a->arr_time > b->arr_time ? 1 : -1; 
}
double SJF(struct process time[],int n, double exit){
	double minburst = 1000000;
	int index = -1,j;
	for(j = 0;j<n;j++)if (time[j].passed == 0 && time[j].arr_time<=exit && minburst>time[j].burst_time){
		minburst = time[j].burst_time;
		index = j;
	}
	if(index != -1 ){
		time[index].passed = 1;
		return exit + time[index].burst_time;
	}
	for(j = 0;j<n;j++)if (time[j].passed == 0)return time[j].arr_time + time[j].burst_time;
} 
double max(double a, double b){
	return a>b?a:b;
}
int main(){
int i,n;
double a,b,exit=0,tat,wt,avgturn,avgwait,sumwt,sumtat;
struct process time[1000];
scanf("%d",&n);
for(i = 0;i<n;i++){
time[i].ind=i;
time[i].passed = 0;
scanf("%lf%lf",&a,&b);
time[i].arr_time = a;
time[i].burst_time = b;
}
qsort(time, n, sizeof(time[0]), compare);
printf("i\tCT\t\tTAT\t\tWT\n");
for(i=0;i<n;i++){
exit = SJF(time, n, exit);

tat = exit - time[i].arr_time;
wt = tat-time[i].burst_time;
sumtat+=tat;
sumwt+=wt;
printf("%d\t%f\t%f\t%f\n",time[i].ind,exit,tat,wt);
}//index is saved before sorting, so it is index of initially ordered data. 
printf("avgTAT = %f\tavgWT = %f",sumtat/n,sumwt/n);

return 0;
}

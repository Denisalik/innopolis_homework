#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int i;
	for(i=0;i<10;i++){
		int* ptr = malloc(10*1024*1024);
		memset(ptr,0,10*1024*1024);
		sleep(1);
		//ex2
		//obiously free is decreasing as time goes until 10 sec passed, and then it returns to initial value
		//si and so most of the time is 0 but sometimes it is not
		//In my case at the start si=6 so=54 then it is 0
		//at the end of one of the runs si=0 so=2824
		//but most of the times it si=0 so=0
		
		//ex3
		//VIRT and RES are increasing as time goes
		//SHR ~ 1024
		//%MEM is increasing too
		//%CPU doesn't have a pattern(sometimes it is 1-0, another time is 5-3, or 0-7)
	}
}

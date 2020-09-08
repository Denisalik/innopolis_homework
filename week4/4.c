#include <stdlib.h>
#include <stdio.h>
int main(){
int i=0,j=0,k=0;
char command[100];
for(;;){
char* arguments[100];
fgets(command, 100, stdin);
for(i=0;i<100;i++)arguments[i] = NULL;

arguments[0] = (char*)malloc(100);
for(i=0;;i++){
if(command[i] == ' '){
j++;
k=0;
arguments[j] = (char*)malloc(100);
}
else if(command[i]!='\n' && command[i]!='\0'){
arguments[j][k]=command[i];
k++;
}
else break;
}
printf("%s\n%s\n",arguments[0],arguments[1]);
int pid=fork();
if(pid==0)execvp(arguments[0], arguments, NULL);
}
return 0;
}

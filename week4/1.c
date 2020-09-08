#include <stdio.h>
#include <sys/types.h>
int main(int argc, char *argv[]){
int n;
sscanf(argv[1], "%d", &n);
//int n = (int)argv[1];
int parent = fork();
if(parent>0)printf("Hello from parent [%d - %d]\n", getpid(), n);
else printf("Hello from child [%d - %d]\n", getpid(), n);
return 0;//it will print PCPCPCPCPC...
}

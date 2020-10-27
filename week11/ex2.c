#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/mman.h>

int main(int argc, char* argv[]){
	const char* str = "Hello";
	char buffer[128];
	int mode = _IOLBF;
	setvbuf(stdout, buffer, mode, sizeof(buffer));
	int i;
	for(i = 0; i < 5; i++){
		printf("%c", str[i]);
		sleep(1);
	}
	fflush(stdout);
    	return 0;
}

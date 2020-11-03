#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	int i;
	int desc[argc];
	int append = 0;
	char c;
	if(strcmp(argv[1], "-a") == 0)append = 1;
	if(append){
		for(i = 2;i < argc; i++){
			desc[i - 2] = open(argv[i], O_RDWR | O_APPEND, 0777);
		}
		desc[argc-2] = STDOUT_FILENO;
		
	}
	else {
		for(i = 1;i < argc; i++){
			desc[i - 1] = open(argv[i], O_RDWR, 0777);
		}
		desc[argc-1] = STDOUT_FILENO;
	}
	while(read(STDIN_FILENO, &c, 1) > 0){
		for(i = 0;i <= ((append==1) ? (argc-2) : (argc-1)); i++){
			write(desc[i], &c, 1);
		}
	}
	for(i = 0;i < ((append==1) ? (argc-2) : (argc-1)); i++){
			close(desc[i]);
		}
}

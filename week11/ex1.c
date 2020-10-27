#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	const char* filepath = "./ex1.txt";
	const char* str = "This is a nice day";
	int fd = open(filepath, O_RDWR);
	if(fd < 0){
        	printf("\n\"%s \" could not open\n", filepath);
        	exit(1);
	}
    	struct stat statbuf;
    	int err = fstat(fd, &statbuf);
    	if(err < 0){
        	printf("\n\"%s \" could not open\n", filepath);
        	close(fd);
        	exit(2);
    	}
    	size_t size = strlen(str);
    	ftruncate(fd, size);
    	char *map = (char*)mmap(NULL, statbuf.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    	if(map == MAP_FAILED){
        	printf("Mapping Failed\n");
        	close(fd);
        	return 1;
    	}
    	strcpy(map, str);
    	munmap(map, size);
    	close(fd);
    	return 0;
}

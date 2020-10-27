#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	const char* inPath = "./ex1.txt";
	const char* outPath = "./ex1.memcpy.txt";
	int in = open(inPath, O_RDONLY);
	int out = open(outPath, O_RDWR | O_CREAT, 0777);
	if(in < 0){
        	printf("\n\"%s \" could not open\n", inPath);
        	exit(1);
	}
	if(out < 0){
        	printf("\n\"%s \" could not open\n", outPath);
        	exit(1);
	}
    	struct stat statbuf;
    	int err = fstat(in, &statbuf);
    	if(err < 0){
        	printf("\n\"%s \" could not open\n", inPath);
        	close(in);
        	close(out);
        	exit(2);
    	}
    	ftruncate(out, statbuf.st_size);
    	char *mapin = (char*)mmap(NULL, statbuf.st_size, PROT_READ, MAP_SHARED, in, 0);
    	char *mapout = (char*)mmap(NULL, statbuf.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, out, 0);
    	if(mapin == MAP_FAILED || mapout == MAP_FAILED){
        	printf("Mapping Failed\n");
        	close(in);
        	close(out);
        	return 1;
    	}
    	memcpy(mapout, mapin, statbuf.st_size);
    	munmap(mapin, statbuf.st_size);
    	munmap(mapout, statbuf.st_size);
    	close(in);
    	close(out);
    	return 0;
}

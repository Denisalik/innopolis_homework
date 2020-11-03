#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	FILE* out = fopen("./ex1.txt", "w");
	FILE* random = fopen("/dev/random", "r");
	char string[20];
	fscanf(random, "%20s", string);
	fprintf(out, "%20s", string);
	close(random);
	close(out);
}

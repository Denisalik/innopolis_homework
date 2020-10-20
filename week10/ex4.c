#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main(){
	DIR* dirp = opendir("./tmp");
	struct stat buff;
	struct dirent* dp;
	if (dirp == NULL) return 0;
	while ((dp = readdir(dirp))!=NULL) {
		if(strcmp(dp->d_name, ".") && strcmp(dp->d_name, "..")){
			char* c = malloc(strlen("./tmp/") + strlen(dp->d_name) + 1);
			strcpy(c, "./tmp/");
			strcat(c,dp->d_name);
			stat(c,&buff);
			if(buff.st_nlink>1){
				printf("File is:%s\nIt's inode:%d\nAll links to file:\n",dp->d_name, buff.st_ino);
				char* inode= malloc(100);
				sprintf(inode, "%d", buff.st_ino);
				char* arguments[5] = {"find", "./", "-inum", inode, NULL};
				execvp(arguments[0], arguments);
			printf("\n");
			}
		}
	}
	closedir(dirp);
	return 0;
}

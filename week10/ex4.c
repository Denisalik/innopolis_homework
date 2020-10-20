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
	if (dirp == NULL) return 0;//if there is no directory
	while ((dp = readdir(dirp))!=NULL) {
		if(strcmp(dp->d_name, ".") && strcmp(dp->d_name, "..")){
			//ignore .(current) and ..(previous) directories
			char* c = malloc(strlen("./tmp/") + strlen(dp->d_name) + 1);
			strcpy(c, "./tmp/");
			strcat(c,dp->d_name);
			stat(c,&buff);
			//c = is path to file, because ex4.c not inside tmp directory we need to add path(./temp) to name of the file
			if(buff.st_nlink>1){
				printf("File is:%s\nIt's inode:%d\nAll links to file:\n",dp->d_name, buff.st_ino);
				char* inode= malloc(100);
				//inode is string version of buff.st_ino
				sprintf(inode, "%d", buff.st_ino);
				char* arguments[5] = {"find", "./", "-inum", inode, NULL};
				//we can use find command because we know inode of the file
				execvp(arguments[0], arguments);
				//find all files that are linked to file with more than 0 links to it
				printf("\n");
			}
		}
	}
	closedir(dirp);
	//close directory
	return 0;
}

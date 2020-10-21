#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

struct visited {
	char* name[10];
};
void listfiles(char* name, struct visited* vis){
	DIR* dirp = opendir(name);
	struct stat buff;
	struct dirent* dp;
	if (dirp == NULL) return;
	while ((dp = readdir(dirp))!=NULL) {
		if(strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)continue;
		if(dp->d_type == DT_DIR){
			char path[200];
			strcpy(path, name);
			strcat(path, dp->d_name);
			strcat(path, "/");
			listfiles(path, vis);
			continue;
		}
		else {
			char* c = malloc(strlen(name) + strlen(dp->d_name) + 1);
			strcpy(c, name);
			strcat(c,"/");
			strcat(c,dp->d_name);
			stat(c,&buff);
			if(buff.st_nlink>1){
				char* inode= malloc(100);
				sprintf(inode, "%d", buff.st_ino);
				int i;
				for(i=0;i<10;i++){
					if(vis->name[i]==NULL){
						vis->name[i] = inode;
						int pid = fork();
						if(pid==0){
							printf("File is:%s\nIt's inode:%d\nAll links to file:\n",dp->d_name, buff.st_ino);
							char* arguments[5] = {"find", "./tmp/", "-inum", inode, NULL};
							execvp(arguments[0], arguments);
						}
						break;
					}
					if(strcmp(vis->name[i], inode)==0)break;
				}
			}
		}
	}
	closedir(dirp);
}

int main(){
	struct visited vis;
	int i;
	for(i = 0;i<10;i++)vis.name[i] = NULL;
	listfiles("./tmp/", &vis);
	return 0;
}

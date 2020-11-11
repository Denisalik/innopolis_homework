#include <stdio.h>
#include <stdlib.h>

int main(){
	int i = 0;
	int k;
	int p;
	FILE* fp = fopen("input_dl.txt", "r");
	int c[100][100];
	int r[100][100];
	int e[100];
	int a[100];
	char temp; 
	do{
	  	fscanf(fp, "%d%c", &e[i], &temp); 
	  	i++; 
	} while(temp!= '\n');
	fscanf(fp,"%c",&temp);
	int m = i;
	for(i = 0; i < m; i++){
		fscanf(fp,"%d",&a[i]);
	}
	int j = 0;
	char temp2;
	do{
		for(i = 0;i < m; i++){
			fscanf(fp,"%d%c",&c[j][i], &temp);
		}
		temp2 = getc(fp);
		if(temp2 == '\n')break;
		ungetc(temp2,fp);
		j++;
	} while(1);
	int n = j+1;
	
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			fscanf(fp, "%d", &r[i][j]);
		}
	}
	
	int proc[100];
	for(i = 0; i < n;i++){
		proc[i] = 0;
	}
	for(k = 0; k < n;k++){
		for(i = 0; i < n;i++){
			if(proc[i]==0){
				for(j = 0; j < m;j++){
					if(a[j] < r[i][j])break;
					if(j == m-1){
						proc[i] = 1;
						for(p = 0;p < m; p++){
							a[p] += c[i][p];
						}
					}
				}
			}	
		}
	}
	int sum = 0;
	for(i = 0; i < n; i++){
		sum += proc[i];
	}
	if(n - sum != 0)printf("%s%d", "number of processes that are deadlocked:", n - sum);
	else printf("no deadlock is detected");
	fclose(fp);
	
}

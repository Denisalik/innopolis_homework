int main(){
int i;
for(i=0;i<3;i++)fork();
system("pstree -p");
return 0;
}

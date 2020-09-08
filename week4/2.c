int main(){
int i;
//for(i=0;i<3;i++)fork();//2^3=8 processes
for(i=0;i<5;i++)fork();//2^5=32 processes
system("pstree -p");
return 0;
}

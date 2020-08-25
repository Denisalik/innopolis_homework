#include <stdio.h>
int main() {
    char c[100];
    char rev[100];
    int k = 0;
    scanf("%s",c);
    int i;
    for(i = 0;c[i]!='\0';i++)k=i;//qwe->k=2
    printf("%d\n",k);
    for(int j = 0;j<=i-1 && k>=0;j++){rev[j] = c[k--];}
    printf("%s",rev);
    return 0;
}

#include <stdio.h>
void swap(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;
    return;
}
int main() {
    int a;
    int b;
    scanf("%d",&a);
    scanf("%d",&b);
    printf("%d %d - old values\n",a,b);
    swap(&a,&b);
    printf("%d %d - new values",a,b);
    return 0;
}

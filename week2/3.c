#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    for(int j = 0;j<n;j++) {
        for (int i = 0; i < n - 1 - j; i++)printf(" ");
        for (int i = 0; i < j+1; i++)printf("*");
        for (int i = 0; i < n - 1 - j; i++)printf(" ");
        printf("\n");
    }
    return 0;
}

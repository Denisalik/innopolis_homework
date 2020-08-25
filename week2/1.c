#include <stdio.h>
#include <limits.h>
#include <float.h>
int main() {
    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;

    printf("size of int:%d value: %d\n",sizeof(a),a);
    printf("size of float:%d value: %f\n",sizeof(b),b);
    printf("size of double:%d value: %f",sizeof(c),c);
    return 0;
}

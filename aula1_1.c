#include <stdio.h>

int main(){

    int a=1, b=2, c=3, d=4;

    printf("antigo a: %d\n", a);

    int *ptr_int1, *ptr_int2, *ptr_int3, *ptr_int4;
    ptr_int1 = &a;
    ptr_int2 = &b;
    ptr_int3 = &c;
    ptr_int4 = &d;

    scanf("%d", ptr_int1);

    printf("novo a: %d\n", a);

    return 0;
}
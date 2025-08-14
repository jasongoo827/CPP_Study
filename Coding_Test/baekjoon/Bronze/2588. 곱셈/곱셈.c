#include <stdio.h>

int main() {
    int a, b;
    int x, y, z, temp;
    scanf("%d %d", &a, &b);
    
    x=b/100;
    temp=b%100;
    y=temp/10;
    z=temp%10;
    
    printf("%d\n", a*z);
    printf("%d\n", a*y);
    printf("%d\n", a*x);
    printf("%d\n", a*b);
    return 0;
}
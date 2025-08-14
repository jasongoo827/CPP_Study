#include <stdio.h>

int main() {
    int n, m;
    long long integer;
    long long mul=1;
    scanf("%d %d", &n, &m);
    
    for(int i=0;i<n;i++){
        scanf("%lld", &integer);
        mul*=(integer%m);
        mul%=m;
    }
    printf("%lld", mul);
    return 0;
}
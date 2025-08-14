#include <stdio.h>

int main()
{
    int N, res;
    int a, b, c, d;
    int cnt=0;
    
    scanf("%d", &N);
    
    res=N;
    
    while(1){
        a=N/10;
        b=N%10;
        c=(a+b)%10;
        d=10*b+c;
        N=d;
        cnt++;
        if(res==d)
            break;
    }
    printf("%d", cnt);
}
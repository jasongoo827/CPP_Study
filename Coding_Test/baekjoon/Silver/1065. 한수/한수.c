#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, numHan=0, temp, cnt=0;
    int hun, ten, one;

    scanf("%d", &N);

    if(N<100) numHan=N;
    else{
        for(int i=100;i<=N;i++){
            hun=i/100;
            temp=i%100;
            ten=temp/10;
            one=temp%10;
            if(hun-ten==ten-one) cnt++;
            numHan=cnt+99;
        }
    }

    printf("%d", numHan);

    return 0;
}

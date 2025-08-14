#include <stdio.h>

int main()
{
    int i,j,n,a,cnt=0;
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &a);
        for(j=2;j<a;j++){
            if(a%j==0) break;
        }
        if(j==a) cnt++;
    }
    printf("%d\n", cnt);
}
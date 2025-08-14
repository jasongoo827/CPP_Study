#include <stdio.h>

int main()
{
    int a, b, c, x;
    int num[10]={0,};
    scanf("%d %d %d", &a, &b, &c);
    x=a*b*c;
    while(x>0){
        num[x%10]++;
        x/=10;
    }
    for(int i=0;i<10;i++){
        printf("%d\n", num[i]);
    }
}
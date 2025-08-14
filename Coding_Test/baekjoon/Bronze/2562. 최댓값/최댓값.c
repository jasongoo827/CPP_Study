#include <stdio.h>

int main()
{
    int num;
    int max=0, maxIndex=1;
    
    for(int i=1;i<=9;i++){
        scanf("%d", &num);
        if(num>max){
            max=num;
            maxIndex=i;
        }
    }
    printf("%d\n%d", max, maxIndex);
    return 0;
}
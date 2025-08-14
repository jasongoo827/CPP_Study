#include <stdio.h>

int main() {
    int x, i=1;
    int sum1=0, sum2=1;
    scanf("%d", &x);
    
    while(1){
        if(x>sum1&&x<=sum2){
            if(i%2!=0){
                printf("%d/%d", (i+1)-(x-sum1), x-sum1);
                break;
            }
            else{
                printf("%d/%d",  x-sum1, (i+1)-(x-sum1));
                break;
            }
        }
        else{
            sum1+=i;
            sum2+=i+1;
            i++;
        }
    }
    
    return 0;
}

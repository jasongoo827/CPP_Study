#include <stdio.h>

int main() {
    int N, sum1=0, sum2=1, cnt=2;
    int i=1;
    scanf("%d", &N);
    
    if(N==1){
        printf("1");
    }
    else{
        while(1){
            double A=(double)(N-1)/6;
            if(A>=sum1&&A<=sum2){
                break;
            }
            else{
                sum1+=i;
                sum2+=i+1;
                i++;
                cnt++;
            }
        }
        printf("%d", cnt);
    }
    return 0;
}
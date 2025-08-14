#include <stdio.h>

int main() {
    int n, m;
    int i, j, k;
    int max=0, sum=0;
    
    scanf("%d %d", &n, &m);
    
    int cardNum[n];
    
    for(i=0;i<n;i++){
        scanf("%d", &cardNum[i]);
    }
    for(i=0;i<n-2;i++){
        for(j=i+1;j<n-1;j++){
            for(k=j+1;k<n;k++){
                sum=cardNum[i]+cardNum[j]+cardNum[k];
                if(sum>m) continue;
                else{
                    if(sum>max){
                        max=sum;
                    }
                }
            }
        }
    }
    printf("%d", max);
    return 0;
}
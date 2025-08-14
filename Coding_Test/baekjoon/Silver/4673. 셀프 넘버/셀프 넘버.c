#include <stdio.h>
#define N 10000

int dn(int n){
    int result=n;
    while(n!=0){
        result+=n%10;
        n/=10;
    }
    return result;
}

int main(){
    int selfNum[N]={0,};
    int i, index;

    for(i=1;i<N;i++){
        index=dn(i);
        if(index<=N){
            selfNum[index]=1;
        }
    }
    for(i=1;i<N;i++){
        if(selfNum[i]!=1){
            printf("%d\n",i);
        }
    }
        
    return 0;
}
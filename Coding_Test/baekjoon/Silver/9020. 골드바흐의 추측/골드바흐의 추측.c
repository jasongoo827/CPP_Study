#include <stdio.h>

int checkPrimeNum(int n){
    int num[10001]={0,1};
    int i, j;
    
    for(i=2;i<=n;i++){
        for(j=2;i*j<=n;j++){
            num[i*j]=1;
        }
    }
    if(!num[n]){
        return 0;
    }
    else{
        return 1;
    }
}

int main() {
    int a, b, t, n;
    
    scanf("%d", &t);
    for(int i=0;i<t;i++){
        scanf("%d", &n);
        a=n/2;
        b=n/2;
        while(checkPrimeNum(a)||checkPrimeNum(b)){
            a+=1;
            b-=1;
        }
        printf("%d %d\n", b, a);
    }
    return 0;
}
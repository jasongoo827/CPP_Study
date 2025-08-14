#include <stdio.h>

int main() {
    int m,n,i,j;
    int num[1000001]={0,1};
    
    scanf("%d %d", &m, &n);
    
    for(i=2;i<=n;i++){
        for(j=2;i*j<=n;j++){
            num[i*j]=1;
        }
    }
    for(i=m;i<=n;i++){
        if(!num[i]){
            printf("%d\n", i);
        }
    }
    return 0;
}
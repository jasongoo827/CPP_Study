#include <stdio.h>

int main() {
    int n;
    int num[1000001]={1,0};
    for(int i=2;i<=1000001;i++){
        for(int j=2;i*j<=1000001;j++){
            num[i*j]=1;
        }
    }
    while(1){
        scanf("%d", &n);
        if(n==0) break;
        int a=3, b=n-a;
        while(1){
            if(a==n){
                printf("Goldbach's conjecture is wrong.");
                break;
            }
            if(!num[a]&&!num[b]){
                printf("%d = %d + %d\n", n, a, b);
                break;
            }
            else{
                a++, b--;
            }
        }
    }
    return 0;
}
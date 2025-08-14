#include <stdio.h>

int fibo(int N){
    if(N==0){
        return 0;
    }
    else if(N==1){
        return 1;
    }
    return fibo(N-2)+fibo(N-1);
}

int main() {
    int N;
    scanf("%d", &N);
    printf("%d", fibo(N));
    return 0;
}
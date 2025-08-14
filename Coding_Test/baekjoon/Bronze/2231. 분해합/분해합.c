#include <stdio.h>

int produce(int n){
    int result=0;
    while(n!=0){
        result+=(n%10);
        n/=10;
    }
    return result;
}

int main() {
    int n, i;
    int min=1000000;
    scanf("%d", &n);
    
    for(i=1;i<n;i++){
        if((produce(i)+i)==n){
            if(i<min){
                min=i;
            }
        }
    }
    if(min==1000000){
        printf("0");
    }
    else{
        printf("%d",min);
    }
    return 0;
}
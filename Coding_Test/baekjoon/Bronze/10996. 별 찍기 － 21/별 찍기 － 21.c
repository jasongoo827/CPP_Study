#include <stdio.h>

int main() {
    int i, j;
    int n;
    scanf("%d", &n);
    
    for(i=1;i<=2*n;i++){
        if(i%2!=0){
            for(j=1;j<=n;j++){
                if(j%2!=0){
                    printf("*");
                }
                else{
                    printf(" ");
                }
            }
            printf("\n");
        }
        else{
            for(j=1;j<=n;j++){
                if(j%2!=0){
                    printf(" ");
                }
                else{
                    printf("*");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
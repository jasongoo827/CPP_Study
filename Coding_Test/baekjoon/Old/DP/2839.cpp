#include <stdio.h>
#include <stdlib.h>


int main()
{
    int N, mod;
    int num;
    int min;
    scanf("%d", &N);

    num=N/5;
    mod=N%5;

    for(int i=0;i<=num;i++){
        if(N%5==0){
            min=num;
            break;
        }
        else if(N==1||N==2||N==4||N==7){
            min=-1;
        }
        else{
            if(mod%3==0){
                min=((N-mod)/5)+(mod/3);
                break;
            }
            else mod+=5;
        }
    }

    printf("%d", min);
}

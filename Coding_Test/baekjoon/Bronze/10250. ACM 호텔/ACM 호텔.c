#include <stdio.h>

int main() {
    int T, H, W, N;
    int fl, num, roomNum;
    scanf("%d", &T);
    
    for(int i=0; i<T;i++){
        scanf("%d %d %d", &H, &W, &N);
        if(N>H*W){
            printf("-1");
        }
        else{
            if(N%H==0){
                fl=H;
                num=N/H;
            }
            else{
                fl=N%H;
                num=N/H+1;
            }
            roomNum=100*fl+num;
            printf("%d\n", roomNum);
        }
    }
    return 0;
}
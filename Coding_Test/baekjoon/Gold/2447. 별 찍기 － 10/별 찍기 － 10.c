#include <stdio.h>

int mat[2201][2201];

void init(){
    for(int i=0;i<2201;i++){
        for(int j=0;j<2201;j++){
            mat[i][j]=' ';
        }
    }
}
void printStar(int N, int y, int x){
    if(N==1){
        mat[y][x]='*';
        return;
    }
    int div=N/3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==1&&j==1){
                continue;
            }
            else{
                printStar(div, y+i*div, x+j*div);
            }
        }
    }
}
int main() {
    int N;
    scanf("%d", &N);
    init();
    printStar(N,0,0);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%c",mat[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
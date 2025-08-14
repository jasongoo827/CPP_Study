#include <bits/stdc++.h>

using namespace std;
#define MAX 2187

int arr[MAX][MAX];
int cnt_Zero=0, cnt_One=0, cnt_Mone=0;

void cal(int num){
    if(num==1) cnt_One++;
    else if(num==0) cnt_Zero++;
    else cnt_Mone++;
}

void cntPaper(int y, int x, int size){
    if(size==1){
        cal(arr[y][x]);
        return;
    }
    bool flag=true;
    int cur=arr[y][x];
    for(int dy=y;dy<y+size;dy++){
        for(int dx=x;dx<x+size;dx++){
            if(cur!=arr[dy][dx]) flag=false;
        }
    }
    if(flag){
        cal(cur);
    }
    else{
        int div=size/3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cntPaper(y+div*i,x+div*j,div);
            }
        }
    }
    return;
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &arr[i][j]);
        }
    }
    cntPaper(0,0,n);
    printf("%d\n", cnt_Mone);
    printf("%d\n", cnt_Zero);
    printf("%d\n", cnt_One);
}
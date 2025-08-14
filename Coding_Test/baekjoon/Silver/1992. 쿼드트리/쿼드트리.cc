#include <bits/stdc++.h>

using namespace std;

int tree[64][64];

void compress(int y, int x, int size){
    if(size==1){
        printf("%d", tree[y][x]);
        return;
    }
    bool zero=true, one=true;
    for(int dy=y;dy<y+size;dy++){
        for(int dx=x;dx<x+size;dx++){
            if(tree[dy][dx]) zero=false;
            else one=false;
        }
    }
    if(zero) printf("0");
    else if(one) printf("1");
    else{
        printf("(");
        compress(y,x,size/2);
        compress(y,x+size/2,size/2);
        compress(y+size/2,x,size/2);
        compress(y+size/2,x+size/2,size/2);
        printf(")");
    }
    return;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++){
            tree[i][j]=s[j]-'0';
        }
    }
    compress(0,0,n);
}
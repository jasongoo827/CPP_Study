#include <bits/stdc++.h>

using namespace std;

int ret=0;

int quadrant(int r, int c, int size){
    if(r+1<=size&&c+1<=size) return 0;
    else if(r+1<=size&&c+1>size) return 1;
    else if(r+1>size&&c+1<=size) return 2;
    else return 3;
}

void findRC(int r, int c, int size, int visit){
    if(size==2){
        ret+=(visit+quadrant(r,c,size/2));
        return;
    }
    int half=size/2;
    if(quadrant(r,c,half)==0){
        findRC(r,c,half,visit);
    }
    else if(quadrant(r,c,half)==1){
        findRC(r,c-half,half,visit+half*half);
    }
    else if(quadrant(r,c,half)==2){
        findRC(r-half,c,half,visit+half*half*2);
    }
    else{
        findRC(r-half,c-half,half,visit+half*half*3);
    }
    return;
}

int main() {
    int n, r, c;
    scanf("%d %d %d", &n, &r, &c);
   
    int size=1;
    for(int i=0;i<n;i++){
        size*=2;
    }
    findRC(r,c,size,0);
    printf("%d", ret);
}
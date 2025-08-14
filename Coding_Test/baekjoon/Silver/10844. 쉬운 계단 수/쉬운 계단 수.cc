#include <bits/stdc++.h>

using namespace std;

int ans;
long cache[101][10];
long MOD=1000000000;

long stairNum(int n, int x){
    if(n==1) return x==0?0:1;
    
    long& ret=cache[n][x];
    if(ret!=-1) return ret;
    
    if(x==0) return ret=stairNum(n-1,1)%MOD;
    if(x==9) return ret=stairNum(n-1,8)%MOD;
    else{
        return ret=(stairNum(n-1,x-1)+stairNum(n-1,x+1))%MOD;
    }
    
}

int main() {
    int n;
    scanf("%d", &n);
    memset(cache,-1,sizeof(cache));
    for(int i=0;i<10;i++){
        ans=(ans+stairNum(n,i))%MOD;
    }
    printf("%d", ans);
}
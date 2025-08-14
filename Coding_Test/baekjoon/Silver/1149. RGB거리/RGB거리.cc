#include <bits/stdc++.h>

using namespace std;

int n, INF=987654321;
int cache[1001][3];
int cost[1001][3];

int solve(int pos, int color){
    if(pos==n-1) return cost[pos][color];
    
    int& ret=cache[pos][color];
    if(ret!=-1) return ret;
    
    return ret=min(solve(pos+1,(color+1)%3), solve(pos+1,(color+2)%3))+cost[pos][color];
}

int main() {
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            scanf("%d", &cost[i][j]);
        }
    }
    memset(cache,-1,sizeof(cache));
    int ret=INF;
    for(int i=0;i<3;i++){
        ret=min(ret,solve(0,i));
    }
    printf("%d", ret);
}
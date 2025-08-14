#include <bits/stdc++.h>

using namespace std;

int cache[1001];
int MOD=10007;

int tiling(int width){
    if(width<=1) return 1;
    
    int& ret=cache[width];
    if(ret!=-1) return ret;
    
    return ret=(tiling(width-1)+tiling(width-2))%MOD;
}

int main() {
    int n;
    scanf("%d", &n);
    memset(cache,-1,sizeof(cache));
    printf("%d", tiling(n));
}
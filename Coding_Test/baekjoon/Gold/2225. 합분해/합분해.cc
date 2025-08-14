#include <bits/stdc++.h>

typedef long long ll;
#define MOD 1000000000

using namespace std;

ll cache[201][201];

int solve(int n, int k){
    if(k==1) return 1;
    
    ll& ret=cache[n][k];
    if(ret!=-1) return ret;
    
    ret=0;
    for(int i=0;i<=n;i++){
        ret=(ret+solve(n-i,k-1))%MOD;
    }
    return ret;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    memset(cache,-1,sizeof(cache));
    printf("%d", solve(n,k));
}
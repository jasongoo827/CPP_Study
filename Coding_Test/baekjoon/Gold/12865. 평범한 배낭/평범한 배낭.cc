#include <bits/stdc++.h>

using namespace std;

int n,k;
int cache[101][100001], wei[101], val[101];

int maxValue(int start, int k){
    if(start==n) return 0;
    
    int& ret=cache[start][k];
    if(ret!=-1) return ret;
    
    ret=0;
    ret=max(ret,maxValue(start+1,k));
    if(k>=wei[start]){
        ret=max(ret,maxValue(start+1,k-wei[start])+val[start]);
    }
    return ret;
}

int main() {
    scanf("%d %d", &n, &k);
    
    for(int i=0;i<n;i++){
        scanf("%d %d", &wei[i], &val[i]);
    }
    memset(cache,-1,sizeof(cache));
    printf("%d", maxValue(0,k));
}
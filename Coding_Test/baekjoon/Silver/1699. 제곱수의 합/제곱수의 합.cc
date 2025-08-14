#include <bits/stdc++.h>

using namespace std;

int n;
int cache[100001];

int cntHang(int sum){
    if(sum==n) return 0;
    
    int& ret=cache[sum];
    if(ret!=-1) return ret;
    
    ret=987654321;
    for(int i=1;i*i<=n;i++){
        if(sum+i*i<=n){
            ret=min(ret,cntHang(sum+i*i)+1);
        }
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    memset(cache,-1,sizeof(cache));
    printf("%d", cntHang(0));
}
#include <bits/stdc++.h>

using namespace std;

int n, INF=987654321;
int pack[10001];
int cache[1000];

int minPayment(int card){
    if(card==n) return 0;
    
    int& ret=cache[card];
    if(ret!=-1) return ret;
    
    ret=INF;
    for(int i=1;i<=n;i++){
        if(card+i<=n){
            ret=min(ret,minPayment(card+i)+pack[i]);
        }
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &pack[i]);
    }
    memset(cache,-1,sizeof(cache));
    printf("%d", minPayment(0));
}
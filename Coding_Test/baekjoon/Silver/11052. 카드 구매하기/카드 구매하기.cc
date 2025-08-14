#include <bits/stdc++.h>

using namespace std;

int n;
int pack[10001];
int cache[1000];

int maxPayment(int card){
    if(card==n) return 0;
    
    int& ret=cache[card];
    if(ret!=-1) return ret;
    
    ret=0;
    for(int i=1;i<=n;i++){
        if(card+i<=n){
            ret=max(ret,maxPayment(card+i)+pack[i]);
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
    printf("%d", maxPayment(0));
}
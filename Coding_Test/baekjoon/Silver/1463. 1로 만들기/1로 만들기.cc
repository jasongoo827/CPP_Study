#include <bits/stdc++.h>

using namespace std;
#define MAX 1000000
#define INF 987654321

int cache[MAX+1];

int makeOne(int n){
    int& ret=cache[n];
    if(ret!=-1) return ret;
    
    if(n==1) return ret;
    
    ret=INF;
    if(n%3==0){
        ret=min(ret,makeOne(n/3));
    }
    if(n%2==0){
        ret=min(ret,makeOne(n/2));
    }
    ret=min(ret,makeOne(n-1));
    
    return ret=ret+1;
}

int main() {
    int n;
    scanf("%d", &n);
    memset(cache,-1,sizeof(cache));
    cache[0]=cache[1]=0;
    printf("%d", makeOne(n));
}
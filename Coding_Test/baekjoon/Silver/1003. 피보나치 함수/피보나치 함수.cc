#include <bits/stdc++.h>

using namespace std;

int cache[41][2];

int solve(int n, int callNum){
    if(n==0&&callNum==0) return 1;
    if(n==1&&callNum==1) return 1;
    if(n==0&&callNum==1) return 0;
    if(n==1&&callNum==0) return 0;
    
    int& ret=cache[n][callNum];
    if(ret!=-1) return ret;
    
    return ret=solve(n-1, callNum)+solve(n-2, callNum);
}

int main() {
    int testcase;
    scanf("%d", &testcase);
    while(testcase--){
        int n;
        scanf("%d", &n);
        memset(cache,-1,sizeof(cache));
        printf("%d %d\n", solve(n,0), solve(n,1));
    }
}
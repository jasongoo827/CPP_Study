#include <bits/stdc++.h>

using namespace std;

int n;
int A[1000], cache[1001];

int lis(int start){
    int& ret=cache[start+1];
    if(ret!=-1) return ret;
    
    ret=1;
    for(int next=start+1;next<n;next++){
        if(start==-1||A[start]<A[next]){
            ret=max(ret,1+lis(next));
        }
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &A[i]);
    }
    memset(cache,-1,sizeof(cache));
    printf("%d", lis(-1)-1);
}
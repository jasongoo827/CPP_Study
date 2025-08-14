#include <bits/stdc++.h>

using namespace std;

int cache[1001], A[1001], choices[1001];
int n;

int lis(int start){
    int& ret=cache[start+1];
    if(ret!=-1) return ret;
    
    ret=1;
    int bestNext=-1;
    for(int next=start+1;next<n;next++){
        if(start==-1||A[start]<A[next]){
            int cand=lis(next)+1;
            if(cand>ret){
                ret=cand;
                bestNext=next;
            }
        }
    }
    choices[start+1]=bestNext;
    return ret;
}
void reconstruct(int start, vector<int>& seq){
    if(start!=-1) seq.push_back(A[start]);
    int next=choices[start+1];
    if(next!=-1) reconstruct(next,seq);
}

int main() {
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &A[i]);
    }
    memset(cache,-1,sizeof(cache));
    vector<int> seq;
    printf("%d\n", lis(-1)-1);
    reconstruct(-1,seq);
    for(int i=0;i<(int)seq.size();i++){
        printf("%d ",seq[i]);
    }
}
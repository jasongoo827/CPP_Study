#include <bits/stdc++.h>

using namespace std;

int n;
int ans=0;
int visited[15];

bool valid(int line){
    for(int i=0;i<line;i++){
        if(visited[i]==visited[line]) return false;
        else if(line-i==abs(visited[line]-visited[i])) return false;
    }
    return true;
}

void dfs(int line){
    if(line==n){
        ans++;
        return;
    }
    for(int i=0;i<n;i++){
        visited[line]=i;
        if(valid(line)){
            dfs(line+1);
        }
    }
}

int main(){
    scanf("%d", &n);
    dfs(0);
    printf("%d\n", ans);
}
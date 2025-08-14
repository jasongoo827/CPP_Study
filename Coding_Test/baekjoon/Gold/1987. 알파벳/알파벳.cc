#include <bits/stdc++.h>

using namespace std;

char board[21][21];
int r,c;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool visited[26];
int ans=0;

void dfs(int y, int x, int cnt){
    ans=max(ans,cnt);
    
    for(int i=0;i<4;i++){
        int nX=x+dx[i];
        int nY=y+dy[i];
        
        if(nX<0||nX>=c||nY<0||nY>=r){
            continue;
        }
        int n=(int)board[nY][nX]-65;
        if(visited[n]){
            continue;
        }
        visited[n]=true;
        dfs(nY,nX,cnt+1);
        visited[n]=false;
    }
}
int main(){
    scanf("%d %d", &r, &c);
    for(int i=0;i<r;i++){
        getchar();
        for(int j=0;j<c;j++){
            scanf("%c", &board[i][j]);
        }
    }
    for(int i=0;i<26;i++){
        visited[i]=false;
    }
    visited[(int)board[0][0]-65]=true;
    dfs(0,0,1);
    printf("%d", ans);
}
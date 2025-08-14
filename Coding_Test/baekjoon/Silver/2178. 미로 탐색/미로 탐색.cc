#include <bits/stdc++.h>
using namespace std;

int n,m;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
string maze[100];
int cnt[100][100]={0,};
bool visited[100][100]={false,};

void bfs(int a, int b){
  visited[a][b]=true;
  queue<pair<int,int> > q;
  q.push(make_pair(a,b));
  while(!q.empty()){
    int x=q.front().first;
    int y=q.front().second;
    q.pop();
    
    for(int i=0;i<4;i++){
      int nX=x+dx[i], nY=y+dy[i];
      if(nX>=0&&nX<m&&nY>=0&&nY<n&&!visited[nY][nX]&&cnt[nY][nX]==0&&maze[nY][nX]=='1'){
        cnt[nY][nX]=cnt[y][x]+1;
        visited[nY][nX]=true;
        q.push(make_pair(nX,nY));
      }
    }
  }
}

int main(){
  scanf("%d %d", &n, &m);
  for(int i=0;i<n;i++){
    cin>>maze[i];
  }
  bfs(0,0);
  printf("%d", cnt[n-1][m-1]+1);
}



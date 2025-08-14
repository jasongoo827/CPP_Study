#include <bits/stdc++.h>
using namespace std;

int n;
string apt[25];
bool visited[25][25]={false,};
vector<int> comp;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int cnt;

void dfs(int y, int x){
  cnt++;
  visited[y][x]=true;
  for(int i=0;i<4;i++){
    int nX=x+dx[i], nY=y+dy[i];
    if(0<=nX&&nX<n&&0<=nY&&nY<n&&!visited[nY][nX]&&apt[nY][nX]=='1'){
      dfs(nY,nX);
    }
  }
}

int main(){
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    cin>>apt[i];
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(apt[i][j]=='1'&&!visited[i][j]){
        cnt=0;
        dfs(i,j);
        comp.push_back(cnt);
      }
    }
  }
  sort(comp.begin(),comp.end());
  printf("%d\n", comp.size());
  for(int i=0;i<comp.size();i++){
    printf("%d\n", comp.at(i));
  }
}

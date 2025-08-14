#include <bits/stdc++.h>

using namespace std;

int n,m,v;//정점, 간선의 개수, 시작 정점의 번호
int graph[1001][1001];
bool visited[1001];
bool discovered[1001];

void dfs(int here){
  visited[here]=true;
  printf("%d ", here);
  for(int i=1;i<=n;i++){
    if(graph[here][i]==1){
      int there=i;
      if(!visited[there]){
        dfs(there);
      }
    }
  }
}

void bfs(int start){
  queue<int> q;
  discovered[start]=true;
  vector<int> order;
  q.push(start);
  
  while(!q.empty()){
    int here=q.front();
    q.pop();
    order.push_back(here);
    for(int i=1;i<=n;i++){
      if(graph[here][i]==1){
        int there=i;
        if(!discovered[there]){
          q.push(there);
          discovered[there]=true;
        }
      }
    }
  }
  for(int i=0;i<order.size();i++){
    printf("%d ", order.at(i));
  }
}

int main(){ 
  scanf("%d %d %d", &n, &m, &v);
  int a,b; // 받아야하는 두 정점의 번호
  for(int i=0;i<m;i++){
    scanf("%d %d", &a, &b);
    graph[a][b]=1;
    graph[b][a]=1;
  }
  for(int i=0;i<n;i++){
    visited[i]=false;
    discovered[i]=false;
  }
  dfs(v);
  printf("\n");
  bfs(v);
}
#include <bits/stdc++.h>

using namespace std;

int n;
queue<int> q;

int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    q.push(i);
  }
  if(q.size()==1) printf("1");
  else{
    while(1){
    q.pop();
    if(q.size()==1) break;
    q.push(q.front());
    q.pop();
    }
    printf("%d", q.front());
  }
 }
#include <bits/stdc++.h>
using namespace std;

stack<int> s;
int k;

int main(){
  int i, n;
  int sum=0;
  scanf("%d", &k);
  for(i=0;i<k;i++){
    scanf("%d", &n);
    if(n==0){
      if(s.empty()){printf("-1\n");break;}
      else{s.pop();}
    }
    else{
      s.push(n);
    }
  }
  while(!s.empty()){
    sum+=s.top();
    s.pop();
  }
  printf("%d\n", sum);
}
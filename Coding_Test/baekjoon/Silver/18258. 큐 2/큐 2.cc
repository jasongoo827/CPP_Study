#include <bits/stdc++.h>
using namespace std;

queue<int> q;
int n;

int main(){
  int x;
  scanf("%d", &n);
  char cmd[50];
  
  for(int i=0;i<n;i++){
    scanf("%s", cmd);
    if(!strcmp(cmd,"push")){
      scanf("%d", &x);
      q.push(x);
    }
    else if(!strcmp(cmd,"pop")){
      if(q.empty()){
        printf("-1\n");
      }
      else{
        printf("%d\n", q.front());
        q.pop();
      }
    }
    else if(!strcmp(cmd,"size")){
      printf("%d\n", q.size());
    }
    else if(!strcmp(cmd,"empty")){
      if(q.empty()){
        printf("1\n");
      }
      else{
        printf("0\n");
      }
    }
    else if(!strcmp(cmd,"front")){
      if(q.empty()){
        printf("-1\n");
      }
      else{
        printf("%d\n", q.front());
      }
    }
    else if(!strcmp(cmd,"back")){
      if(q.empty()){
        printf("-1\n");
      }
      else{
        printf("%d\n", q.back());
      }
    }
  }
}
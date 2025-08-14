#include <bits/stdc++.h>
using namespace std;

typedef struct{
  int x;
  int y;
}DATA;

int n;
DATA coordinate[100000];

bool cmp(DATA a, DATA b){
  if(a.y<b.y) return true;
  else if(a.y==b.y){
    if(a.x<b.x) return true;
  }
  return false;
}

int main(){
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    scanf("%d %d", &coordinate[i].x, &coordinate[i].y);
  }
  
  sort(coordinate,coordinate+n,cmp);
  
  for(int i=0;i<n;i++){
    printf("%d %d\n", coordinate[i].x, coordinate[i].y);
  }
}
#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b){
  return a>b;
}
int n;
int cnt=0;
int num[10];

int main(){
  int i=0;
  scanf("%d", &n);
  while(n!=0){
    num[i]=n%10;
    n/=10;
    cnt++,i++;
  }
  sort(num,num+cnt,cmp);
  
  for(int i=0;i<cnt;i++){
    printf("%d",num[i]);
  }
}
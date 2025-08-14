#include <bits/stdc++.h>
using namespace std;

typedef struct{
  int age;
  int join;
  char name[101];
}DATA;

bool cmp(DATA a, DATA b){
  if(a.age<b.age) return true;
  else if(a.age==b.age){
    if(a.join<b.join) return true;
  }
  return false;
}

int n;
DATA member[100000];

int main(){
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    scanf("%d %s", &member[i].age, &member[i].name);
    member[i].join=i;
  }
  sort(member,member+n,cmp);
  for(int i=0;i<n;i++){
    printf("%d %s\n", member[i].age, member[i].name);
  }
}

#include <bits/stdc++.h>
using namespace std;

typedef struct{
  char word[51];
}DATA;

bool cmp(DATA a, DATA b){
  if(strlen(a.word)<strlen(b.word)) return true;
  else if(strlen(a.word)==strlen(b.word)){
    if(strcmp(a.word,b.word)<0) return true;
  }
  return false;
}

int n;
DATA EWord[20000];

int main(){
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    scanf("%s", &EWord[i].word);
  }
  sort(EWord,EWord+n,cmp);
  for(int i=0;i<n;i++){
    if(strcmp(EWord[i].word,EWord[i+1].word)==0) continue;
    printf("%s\n", &EWord[i].word);
  }
}
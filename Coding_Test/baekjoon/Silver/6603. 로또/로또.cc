#include <bits/stdc++.h>
using namespace std;

int n;
int lotto[49];


void pick(int n, int arr[], vector<int> &picked, int toPick){
  if(toPick==0){
    for(int i=0;i<picked.size();i++){
      printf("%d ", arr[picked.at(i)]);
    }
    printf("\n");
  }
  int smallest=picked.empty()?0:picked.back()+1;
  for(int i=smallest;i<n;i++){
    picked.push_back(i);
    pick(n,arr,picked,toPick-1);
    picked.pop_back();
  }
}

int main(){
  while(1){
    scanf("%d", &n);
    if(n==0) break;
    vector<int> v;
    for(int i=0;i<n;i++){
      scanf("%d", &lotto[i]);
    }
    pick(n,lotto,v,6);
      printf("\n");
  }
  return 0;
}

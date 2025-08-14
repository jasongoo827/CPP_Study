#include <bits/stdc++.h>
using namespace std;

int k, n;
long long lan[10000];
long long ans;

long long max(long long a, long long b){
  return a>b?a:b;
}

int cntLineNum(long long l){
  int sum=0;
  for(int i=0;i<k;i++){
    sum+=lan[i]/l;
  }
  return sum;
}

void lowerbound(long long start, long long end){
  long long mid;
  while(start<=end){
    mid=(start+end)/2;
    int res=cntLineNum(mid);
    if(res<n){
      end=mid-1;
    }
    else{
      start=mid+1;
      ans=max(mid,ans);
    }
  }
}

int main(){
  scanf("%d %d", &k, &n);
  for(int i=0;i<k;i++){
    scanf("%d", &lan[i]);
  }
  lowerbound(1, 2147483647);
  printf("%lld", ans);
}
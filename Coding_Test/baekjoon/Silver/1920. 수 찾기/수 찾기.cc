#include <bits/stdc++.h>
using namespace std;

int n, m;
int num1[100000];
int num2[100000];

int binary_search(int arr[], int target){
  int start=0, end=n-1;
  int mid;
  while(start<=end){
    mid=(start+end)/2;
    if(arr[mid]==target){
      return 1;
    }
    else{
      if(arr[mid]<target){
        start=mid+1;
      }
      else{
        end=mid-1;
      }
    }
  }
  return 0;
}

int main(){
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    scanf("%d", &num1[i]);
  }
  sort(num1,num1+n);
  scanf("%d", &m);
  for(int i=0;i<m;i++){
    scanf("%d", &num2[i]);
    printf("%d\n", binary_search(num1,num2[i]));
  }
}
#include <bits/stdc++.h>

using namespace std;

int n, total, ans;
int bud[10000];

int max(int a, int b){
    return a>b?a:b;
}

int sumBud(int x){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=(bud[i]>x)?x:bud[i];
    }
    return sum;
}

void lowerbound(int start, int end){
     int mid;
     while(start<=end){
         mid=(start+end)/2;
         if(sumBud(mid)>total){
             end=mid-1;
         }
         else{
             start=mid+1;
             ans=max(ans,mid);
         }
     }
} 

int main() {
    int right=0;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &bud[i]);
        if(right<bud[i]) right=bud[i];
    }
    scanf("%d", &total);
    lowerbound(0,right);
    printf("%d", ans);
}
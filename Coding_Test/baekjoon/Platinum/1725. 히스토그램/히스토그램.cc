#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll maxArea(int left, int right, vector<long long> &h){
    if(left==right) return h[left];
    int mid=(left+right)/2;
    ll ret=max(maxArea(left,mid,h), maxArea(mid+1,right,h));
    
    int lo=mid, hi=mid+1;
    ll height=min(h[lo], h[hi]);
    ret=max(ret, height*2);
    
    while(left<lo||hi<right){
        if(hi<right&&(lo==left||h[hi+1]>h[lo-1])){
            hi++;
            height=min(height, h[hi]);
        }
        else{
            lo--;
            height=min(height, h[lo]);
        }
        ret=max(ret, (hi-lo+1)*height);
    }
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<long long> h(n,0);
    for(int i=0;i<n;i++){
        scanf("%lld", &h[i]);
    }
    printf("%lld\n", maxArea(0,n-1,h));

}
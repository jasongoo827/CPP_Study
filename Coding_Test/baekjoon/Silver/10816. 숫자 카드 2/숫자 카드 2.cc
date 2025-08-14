#include <bits/stdc++.h>

using namespace std;

int n,m;
int card[500000], num[500000];


int main() {
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &card[i]);
    }
    sort(card,card+n);
    
    scanf("%d", &m);
    for(int i=0;i<m;i++){
        scanf("%d", &num[i]);
        printf("%ld ", abs(lower_bound(card,card+n,num[i])-upper_bound(card,card+n,num[i])));
    }
}
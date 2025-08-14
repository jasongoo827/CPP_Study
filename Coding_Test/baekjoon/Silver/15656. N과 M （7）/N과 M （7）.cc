#include <bits/stdc++.h>

using namespace std;

int arr[9];

void pick(int n, vector<int>& picked, int toPick){
    if(toPick==0){
        for(int i=0;i<(int)picked.size();i++){
            printf("%d ", arr[picked[i]]);
        }
        printf("\n");
        return;
    }
    for(int next=0;next<n;next++){
        picked.push_back(next);
        pick(n,picked,toPick-1);
        picked.pop_back();
    }
    return;
}

int main() {
    int n, toPick;
    scanf("%d %d", &n, &toPick);
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    sort(arr,arr+n);
    vector<int> v;
    pick(n,v,toPick);
}
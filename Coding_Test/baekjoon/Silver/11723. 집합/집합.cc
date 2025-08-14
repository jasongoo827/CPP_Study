#include <bits/stdc++.h>

using namespace std;

set<int> S;
set<int> allset={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        string s;
        cin>>s;
        
        int x;
        if(s=="add"){
            cin>>x;
            if(S.find(x)!=S.end()) continue;
            S.insert(x);
        }
        else if(s=="remove"){
            cin>>x;
            if(S.find(x)==S.end()) continue;
            S.erase(x);
        }
        else if(s=="check"){
            cin>>x;
            if(S.find(x)!=S.end()) printf("1\n");
            else printf("0\n");
        }
        else if(s=="toggle"){
            cin>>x;
            if(S.find(x)!=S.end()) S.erase(x);
            else S.insert(x);
        }
        else if(s=="all"){
            S=allset;
        }
        else{
            S.clear();
        }
    }
}
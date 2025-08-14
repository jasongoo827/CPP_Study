#include <bits/stdc++.h>

using namespace std;

bool wellMatched(const string& formula){
    stack<char> s;
    for(int i=0;i<(int)formula.size();i++){
        if(formula[i]=='('){
            s.push(formula[i]);
        }
        else{
            if(s.empty()) return false;
            s.pop();
        }
    }
    return s.empty();
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--){
        string formula;
        cin>>formula;
        if(wellMatched(formula)) printf("YES\n");
        else printf("NO\n");
    }
}
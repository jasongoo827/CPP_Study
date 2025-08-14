#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    
    vector<string> idxToName(n);
    unordered_map<string, int> nameToIdx;
    string s;
    
    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        nameToIdx.insert({s, i + 1});
        idxToName[i] = s;
    }
    
    for (int i = 0; i < m; ++i)
    {
        cin >> s;
        
        if (isdigit(s[0]))
            cout << idxToName[stoi(s) - 1] << '\n';
        else
            cout << nameToIdx[s] << '\n';
    }
    
    return 0;
}

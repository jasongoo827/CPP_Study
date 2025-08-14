#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

void dfs(vector<int>& v, vector<int>& ret, int picked, vector<bool>& used)
{
    if (picked == m)
    {
        for (int num: ret)
            cout << num << " ";
        cout << '\n';
        return;
    }
    
    int prev = -1;
    for (int i = 0; i < n; ++i)
    {
        if (used[i])
            continue;
        if (v[i] == prev)
            continue;
        
        ret[picked] = v[i];
        used[i] = true;
        dfs(v, ret, picked + 1, used);
        used[i] = false;
        prev = v[i];
    }
}

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    
    vector<int> v(n);
    vector<bool> used(n, false);
    
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());
    
    vector<int> ret(m);
    dfs(v, ret, 0, used);
    
    return 0;
}

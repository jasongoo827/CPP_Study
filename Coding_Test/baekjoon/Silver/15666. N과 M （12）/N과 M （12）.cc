#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> ret;
vector<int> v;

void dfs(vector<int>& v, int picked)
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
        if (v[i] == prev)
            continue;
        if (picked > 0 && v[i] < ret[picked - 1])
            continue;
        
        ret[picked] = v[i];
        dfs(v, picked + 1);
        prev = v[i];
    }
}

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    v.resize(n);
    
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());
    
    ret.resize(m);
    dfs(v, 0);
    
    return 0;
}

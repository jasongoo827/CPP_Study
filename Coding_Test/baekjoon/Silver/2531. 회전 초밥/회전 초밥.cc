#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, d, k, c;
    cin >> n >> d >> k >> c;
    vector<int> v(n);
    
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    unordered_map<int, int> umap;
    int ret = 0;
    // 7 9 7 30 2 7 9 25
    for (int i = 0; i < k; ++i)
        umap[v[i]]++;
    
    if (!umap.count(c))
        ret = max(ret, (int)umap.size() + 1);
    else
        ret = max(ret, (int)umap.size());
    
    for (int i = 1; i < n; ++i)
    {
        umap[v[i - 1]]--;
        if (umap[v[i - 1]] == 0)
            umap.erase(v[i - 1]);
        umap[v[(i + k - 1) % n]]++;
        
        if (!umap.count(c))
            ret = max(ret, (int)umap.size() + 1);
        else
            ret = max(ret, (int)umap.size());
    }
    cout << ret << '\n';
    
    return 0;
}
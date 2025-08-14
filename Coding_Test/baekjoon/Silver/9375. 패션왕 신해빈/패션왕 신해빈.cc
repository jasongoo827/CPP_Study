#include <iostream>
#include <unordered_map>

using namespace std;

int t, n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--)
    {
        cin >> n;
        unordered_map<string, int> umap;
        string s1, s2;

        for (int i = 0; i < n; ++i)
        {
            cin >> s1 >> s2;
            if (umap.find(s2) != umap.end())
                umap[s2]++;
            else
                umap[s2] = 1;
        }

        int ret = 1;
        for (auto& [type, count]: umap)
            ret *= (count + 1);
            
        cout << ret - 1 << '\n';
    }

    return 0;
}
#include <iostream>
#include <unordered_map>

using namespace std;

// boj 17219
int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    unordered_map<string, string> umap;

    for (int i = 0; i < n; ++i)
    {
        string s1, s2;
        cin >> s1 >> s2;
        umap.insert({s1, s2});
    }

    for (int i = 0; i < m; ++i)
    {
        string s;
        cin >> s;
        cout << umap[s] << '\n';
    }

    return 0;
}
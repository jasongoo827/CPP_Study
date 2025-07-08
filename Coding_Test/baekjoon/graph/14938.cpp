#include <iostream>
#include <vector>

using namespace std;

// boj 14938

int n, m, r;
const int INF = 987654321;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> r;

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
    vector<int> item(n + 1);

    for (int i = 1; i <= n; ++i)
        cin >> item[i];
    for (int i = 0; i < r; ++i)
    {
        int a, b, l;
        cin >> a >> b >> l;
        dist[a][b] = l;
        dist[b][a] = l;
    }

    for (int i = 1; i <= n; ++i)
        dist[i][i] = 0;

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);

    int ret = 0;
    for (int i = 1; i<= n; ++i)
    {
        int total = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (dist[i][j] <= m)
                total += item[j];
        }
        ret = max(ret, total);
    }
    cout << ret << '\n';

    return 0;
}
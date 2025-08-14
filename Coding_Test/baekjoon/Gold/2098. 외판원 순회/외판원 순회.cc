#include <iostream>
#include <vector>

using namespace std;

int n;
int cost[16][16];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> cost[i][j];
    
    vector<vector<int>> dp(n, vector<int>(1 << n, 1e9));
    dp[0][1 << 0] = 0;
    
    for (int mask = 0; mask < (1 << n); ++mask)
    {
        for (int u = 0; u < n; ++u)
        {
            if (!(mask & (1 << u)))
                continue;
            for (int v = 0; v < n; ++v)
            {
                if (u == v || !(mask & (1 << v)) || cost[v][u] == 0)
                    continue;
                int prev_mask = (mask & ~(1 << u));
                if (dp[v][prev_mask] == 1e9)
                    continue;
                dp[u][mask] = min(dp[u][mask], dp[v][prev_mask] + cost[v][u]);
            }
        }
    }
    
    int ret = 1e9;
    for (int u = 1; u < n; ++u)
    {
        if (cost[u][0] == 0)
            continue;
        ret = min(ret, dp[u][(1 << n) - 1] + cost[u][0]);
    }
    cout << ret << '\n';
    
    return 0;
}

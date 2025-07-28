#include <iostream>
#include <algorithm>

using namespace std;

// boj 17404

int n;
int cost[1000][3];
int dp[1000][3];
const int INF = 1e9;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> cost[i][j];

    int ret = INF;
    for (int first = 0; first < 3; ++first)
    {
        for (int l = 0; l < n; ++l)
            fill(dp[l], dp[l] + 3, INF);
        
        dp[0][first] = cost[0][first];
    
        for (int i = 1; i < n - 1; ++i)
            for (int j = 0; j < 3; ++j)
                for (int k = 0; k < 3; ++k)
                    if (j != k)
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + cost[i][j]);

        for (int j = 0; j < 3; ++j)
        {
            if (j != first)
                for (int k = 0; k < 3; ++k)
                    if (j != k)
                        dp[n - 1][j] = min(dp[n - 1][j], dp[n - 2][k] + cost[n - 1][j]);
        }

        for (int j = 0; j < 3; ++j)
        {
            if (j != first)
                ret = min(ret, dp[n - 1][j]);
        }
    }
    cout << ret << '\n';

    return 0;
}
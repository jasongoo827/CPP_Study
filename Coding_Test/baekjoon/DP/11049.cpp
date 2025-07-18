#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// boj 11049 - 구간 dp

int n;
int row[500];
int col[500];

int cost(int i, int k, int j)
{
    return row[i] * col[k] * col[j];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    
    for (int i = 0; i < n; ++i)
        cin >> row[i] >> col[i];

    for (int i = 0; i < n; ++i)
        dp[i][i] = 0;
    
    for (int len = 2; len <= n; ++len)
    {
        for (int i = 0; i < n - len + 1; ++i)
        {
            int j = i + len - 1;
            for (int k = i; k < j; ++k)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + cost(i, k, j));
            }
        }
    }

    cout << dp[0][n - 1] << '\n';

    return 0;
}
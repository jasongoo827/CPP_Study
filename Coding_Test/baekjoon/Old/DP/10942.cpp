#include <iostream>
#include <vector>

using namespace std;

// boj 10942 - - 구간 dp

int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<int> v(n);
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    for (int i = 0; i < n; ++i)
        dp[i][i] = true;

    for (int i = 0; i < n - 1; ++i)
    {
        if (v[i] == v[i + 1])
            dp[i][i + 1] = true;
    }

    for (int len = 3; len <= n; ++len)
    {
        for (int i = 0; i < n - len + 1; ++i)
        {
            int j = i + len - 1;
            if (v[i] == v[j] && dp[i + 1][j - 1])
                dp[i][j] = true;
        }
    }

    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int s, e;
        cin >> s >> e;

        cout << (dp[s - 1][e - 1] == true ? 1 : 0) << '\n';
    }

    return 0;
}
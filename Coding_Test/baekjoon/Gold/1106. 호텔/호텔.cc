#include <iostream>
#include <vector>

using namespace std;

// boj 1106

int c, n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> c >> n;

    int maxCustomer = 0;
    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i].first >> v[i].second;
        maxCustomer = max(maxCustomer, v[i].second);
    }

    vector<int> dp(c + maxCustomer + 1, 1e9);
    dp[0] = 0;

    for (int i = 1; i <= c + maxCustomer; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int cost = v[j].first;
            int customer = v[j].second;
            dp[i] = min(dp[i], dp[max(0, i - customer)] + cost);
        }
    }

    int ret = 1e9;
    for (int i = c; i <= c + maxCustomer; ++i)
        ret = min(ret, dp[i]);

    cout << ret << '\n';

    return 0;
}
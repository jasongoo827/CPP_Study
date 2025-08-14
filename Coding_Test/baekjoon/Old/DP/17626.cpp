#include <iostream>
#include <cmath>

using namespace std;

// boj 17626

int n;
int dp[50001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    dp[0] = 0;
    for (int i = 1; i * i <= n; ++i)
    {
        dp[i * i] = 1;
    }

    for (int i = 1; i <= n; ++i)
    {
        int minVal = 1e9;
        for (int j = 1; j * j <= i; ++j)
            minVal = min(minVal, dp[i - j * j]);
        dp[i] = minVal + 1;
    }

    cout << dp[n] << '\n';

    return 0;
}
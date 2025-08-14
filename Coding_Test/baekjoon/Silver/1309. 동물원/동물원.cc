#include <bits/stdc++.h>

using namespace std;

const int MOD = 9901;

int n;
int dp[10'0001][3];


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;

    for (int i = 2; i <= n; ++i)
    {
        dp[i][0] += (dp[i - 1][1] + dp[i - 1][2]) % MOD;
        dp[i][1] += (dp[i - 1][0] + dp[i - 1][2]) % MOD;
        dp[i][2] += (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
    }

    cout << (dp[n][0] + dp[n][1] + dp[n][2]) % MOD << endl;

    return 0;
}
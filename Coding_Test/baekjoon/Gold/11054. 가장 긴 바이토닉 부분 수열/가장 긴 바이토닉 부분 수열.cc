#include <bits/stdc++.h>

using namespace std;

int n;
int num[1001], dp[1001], r_dp[1001];
int ret = 0;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> num[i];

    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = i - 1; j >= 1; j--)
        {
            if (num[i] > num[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    for (int i = n; i >= 1; i--)
    {
        r_dp[i] = 1;
        for (int j = i + 1; j <= n; j++)
        {
            if (num[i] > num[j])
                r_dp[i] = max(r_dp[i], r_dp[j] + 1);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        ret = max(ret, dp[i] + r_dp[i] - 1);
    }

    cout << ret;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000001;
int num;
int dp[MAX], pre[MAX];


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> num;

    dp[1] = 0;
    dp[2] = 1;

    pre[1] = 0;
    pre[2] = 1;

    for (int i = 3; i <= num; ++i)
    {
        dp[i] = dp[i - 1] + 1;
        pre[i] = i - 1;

        if (i % 3 == 0 && dp[i / 3] + 1 < dp[i])
        {
            dp[i] = dp[i / 3] + 1;
            pre[i] = i / 3;
        }
        if (i % 2 == 0 && dp[i / 2] + 1 < dp[i])
        {
            dp[i] = dp[i / 2] + 1;
            pre[i] = i / 2;
        }
    }

    cout << dp[num] << '\n';
    while (num != 0)
    {
        cout << num << " ";
        num = pre[num];
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;


int n;

int score[10'0001];
int dp[10'0001];


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> score[i];

    dp[1] = score[1];
    dp[2] = score[1] + score[2];

    for (int i = 3; i <= n; i++)
    {
        dp[i] = max(dp[i - 3] + score[i - 1] + score[i], dp[i - 2] + score[i]);
        dp[i] = max(dp[i - 1], dp[i]);
    }

    cout << dp[n];

    return 0;
}
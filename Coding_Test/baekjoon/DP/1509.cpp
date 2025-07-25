#include <iostream>
#include <vector>

using namespace std;

// boj 1509 - 구간 dp 심화

string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    int n = s.length();

    vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
    vector<int> dp(n + 1, 1e9);

    for (int i = 0; i < n; ++i)
        isPalindrome[i][i] = true;
    
    for (int i = 0; i < n - 1; ++i)
    {
        if (s[i] == s[i + 1])
            isPalindrome[i][i + 1] = true;
    }
    
    for (int len = 3; len <= n; ++len)
    {
        for (int i = 0; i < n - len + 1; ++i)
        {
            int j = i + len - 1;
            if (s[i] == s[j] && isPalindrome[i + 1][j - 1])
                isPalindrome[i][j] = true;
        }
    }

    dp[0] = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (isPalindrome[j][i])
                dp[i + 1] = min(dp[i + 1], dp[j] + 1);
        }
    }
    cout << dp[n] << '\n';

    return 0;
}
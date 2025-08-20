#include <iostream>
#include <vector>

using namespace std;

string s1, s2;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();
    
    vector<vector<int>> dp(n, vector<int>(m, 0));
    
    int maxLen = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (s1[i] == s2[j])
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLen = max(maxLen, dp[i][j]);
            }
        }
    }
    cout << maxLen << '\n';
    
    return 0;
}
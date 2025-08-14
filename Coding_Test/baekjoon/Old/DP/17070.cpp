#include <iostream>

using namespace std;

// boj 17070

int n;
int board[16][16];
int dp[16][16][3];

// 가로, 대각선, 세로
int dy[3] = {0, 1, 1};
int dx[3] = {1, 1, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n; 
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> board[i][j];

    dp[0][1][0] = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            if (board[i][j] == 1)
                continue;
            
            dp[i][j][0] += dp[i][j - 1][0] + dp[i][j - 1][1];

            if (i >= 1)
                dp[i][j][2] += dp[i - 1][j][2] + dp[i - 1][j][1];
            
            if (i >= 1 && j >= 1 && board[i - 1][j] == 0 && board[i][j - 1] == 0)
                dp[i][j][1] += dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2]; 
        }
    }
    cout << dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2] << '\n';
    

    return 0;
}
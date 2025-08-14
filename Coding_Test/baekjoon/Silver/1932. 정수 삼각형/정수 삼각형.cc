#include <iostream>

using namespace std;

int n;
int triangle[500][500];
int dp[500][500];

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i + 1; ++j)
            cin >> triangle[i][j];
    
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i + 1; ++j)
        {
            if (j > 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + triangle[i][j]);
            if (j < i)
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + triangle[i][j]);
        }
    }
    
    int ret = 0;
    for (int i = 0; i < n; ++i)
        ret = max(ret, dp[n - 1][i]);
    cout << ret << '\n';
    
    return 0;
}

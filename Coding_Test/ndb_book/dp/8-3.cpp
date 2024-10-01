#include <iostream>
#define MOD 796796

using namespace std;

int n;
long int dp[1001] = {0,};

int main(void)
{
	cin >> n;

	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= n; ++i)
	{
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % MOD;
	}
	cout << dp[n] << '\n';
}
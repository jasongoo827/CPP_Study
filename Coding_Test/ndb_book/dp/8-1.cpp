#include <iostream>

using namespace std;

int x;
int dp[30001] = {0, };

// 점화식을 작성해보는 것도 도움이 될 수 있다.
int main(void)
{
	cin >> x;

	for (int i = 2; i <= x; ++i)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 5 == 0)
			dp[i] = min(dp[i / 5] + 1, dp[i]);
		if (i % 3 == 0)
			dp[i] = min(dp[i / 3] + 1, dp[i]);
		if (i % 2 == 0)
			dp[i] = min(dp[i / 2] + 1, dp[i]);
	}
	cout << dp[x] << '\n';
}
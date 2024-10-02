#include <iostream>

using namespace std;

int n, m;
int dp[10001] = {1e9,}; // 1e9로 초기화 - memset으로 해야되는지 확인해야 함.
int arr[101];

int main(void)
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	dp[0] = 0;
	// for (int i = 0; i <= m; ++i)
	// {
	// 	for (int j = 0; j < n; ++j)
	// 	{
	// 		int k = arr[j];
	// 		if (k > i || dp[i - k] == 1e9)
	// 			continue;
	// 		else
	// 			dp[i] = min(dp[i], dp[i - k] + 1); 
	// 	}
	// }

	// 이렇게 하는 것이 좀 더 순회를 덜 해서 깔끔.
	for (int i = 0; i < n; ++i)
	{
		for (int j = arr[i]; j <= m; ++j)
			if (dp[j - arr[i]] != 1e9) // 없애도 되는 코드
				dp[i] = min(dp[i], dp[i - k] + 1); 
	}

	if (dp[m] == 1e9)
		cout << "-1\n";
	else
		cout << dp[m] << '\n';	
}
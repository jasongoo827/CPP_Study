#include <iostream>

using namespace std;

int n;
int dp[101] = {0};
int arr[101];

// dp 배열에 대한 정의.
// n개의 정보가 주어졌을 때 얻을 수 있는 식량의 최댓값.
int main(void)
{
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	
	dp[0] = arr[0];
	dp[1] = max(arr[0], arr[1]);
	for (int i = 2; i < n; ++i)
	{
		// 전 식량창고를 선택했을 경우 & 전전 식량창고와 현재 식량창고를 선택했을 경우
		dp[i] = max(dp[i - 1], arr[i] + dp[i - 2]);
	}
	cout << dp[n - 1] << '\n';
}
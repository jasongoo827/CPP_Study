#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define MAX 100000

int n, k;
int a[MAX], b[MAX];

int main(void)
{
	cin >> n >> k;

	for (int i = 0; i < n; ++i)
		cin	>> a[i];
	for (int i = 0; i < n; ++i)
		cin	>> b[i];

	sort(a, a + n);
	sort(b, b + n, greater<>());

	for (int i = 0; i < k; ++i)
	{
		if (a[i] < b[i])
			swap(a[i], b[i]);
		else
			break ;
	}

	// 합을 구할 때는 늘 조심.
	long long sum = 0;
	for (int i = 0; i < n; ++i)
		sum += a[i];
	cout << sum << '\n';
}
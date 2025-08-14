#include <bits/stdc++.h>

using namespace std;

int n, m;
int sum = 0, ret = 0;
vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int end = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	for (int front = 0; front < n; front++)
	{
		while (sum < m && end < n)
		{
			sum += v[end];
			end += 1;
		}

		if (sum == m) ret += 1;
		sum -= v[front];
	}

	cout << ret;

	return 0;
}
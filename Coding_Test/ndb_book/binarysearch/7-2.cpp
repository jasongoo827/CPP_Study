#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;
int ret;

int main(void)
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	int start = 0;
	int end = 1e9;

	while (start <= end)
	{
		long int total = 0;
		int mid = (start + end) / 2;

		for (auto& x: v)
		{
			if (x > mid)
				total += (x - mid);
		}
		if (total < mid)
			end = mid - 1;
		else
		{
			ret = mid;
			start = mid + 1;
		}
	}
	cout << ret << '\n';
}
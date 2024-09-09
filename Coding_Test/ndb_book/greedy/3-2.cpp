#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, m, k;
	int ret = 0;
	vector<int> v;

	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	int first = v[n - 1];
	int second = v[n - 2];
	int cnt = (m / (k + 1)) * k;
	cnt += m % (k + 1);

	ret += first * cnt;
	ret += second * (m - cnt);
	cout << ret << endl;
	return (0);
}

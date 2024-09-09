#include <iostream>

using namespace std;

int n, m;

int main(void)
{
	cin >> n >> m;

	int ret = -1;
	// 꼭 vector에 저장하지 않고, 바로 입력해서 비교하는 방식이 메모리 효율에 좋다.
	for (int i = 0; i < n; ++i)
	{
		int tMin = 10001;
		for (int j = 0; j < m; ++j)
		{
			int x;
			cin >> x;
			tMin = min(tMin, x);
		}
		ret = max(ret, tMin);
	}
	cout << ret << endl;

	return (0);
}

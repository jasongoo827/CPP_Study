#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> itemVec, reqVec;

bool binary_search(vector<int>& v, int target, int start, int end)
{
	if (start > end)
		return false;
	int mid = (start + end) / 2;
	if (v[mid] == target)
		return true;
	else if (v[mid] > target)
		binary_search(v, target, start, mid - 1);
	else
		binary_search(v, target, mid + 1, end);
}

// Counting sort, set을 이용한 방법도 있다. 

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		itemVec.push_back(x);
	}
	sort(itemVec.begin(), itemVec.end());

	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int x;
		cin >> x;
		if (binary_search(itemVec, x, 0, n - 1))
			cout << "yes\n";
		else
			cout << "no\n";
	}
}
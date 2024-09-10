#include <iostream>

using namespace std;

int n;
int ret = 0;

bool isIncluded(int a)
{
	if ((a / 10) == 3 || (a % 10) == 3)
		return true;
	return false;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n + 1; ++i)
	{
		for (int j = 0; j < 60; ++j)
		{
			for (int k = 0; k < 60; ++k)
			{
				if (isIncluded(i) || isIncluded(j) || isIncluded(k))
					ret++;
			}
		}
	}
	cout << ret << endl;
}
#include <iostream>

using namespace std;

int n, k;
int ret = 0;

int main(void)
{
	cin >> n >> k;
	
	while (n >= k)
	{
		while (n % k != 0)
		{
			n -= 1;
			ret += 1;
		}
		n /= k;
		ret += 1;
	}
	while (n > 1)
	{
		n -= 1;
		ret += 1;
	}
	cout << ret << endl;
	return (0);
}

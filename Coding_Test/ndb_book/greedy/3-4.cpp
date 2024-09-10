#include <iostream>

using namespace std;

int n, k;
int ret = 0;

int main(void)
{
	cin >> n >> k;
	
	while (true)
	{
		int target = (n / k) * k;
		ret += (n - target);
		if (n < k)
			break ;
		ret += 1;
		n /= k;
	}
	ret += (n - 1);
	cout << ret << endl;
	return (0);
}

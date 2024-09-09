#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);

	int N = atoi(argv[1]);
	int money[4] = {500, 100, 50, 10};
	int ret = 0;
	int i = 0;

	// N이 0이 될 때까지도 되지만, 동전 종류별로 반복을 하는 것도 된다.
	while (N != 0)
	{
		ret += (N / money[i]);
		N %= money[i++];
	}
	cout << ret << endl;
	return (0);
}

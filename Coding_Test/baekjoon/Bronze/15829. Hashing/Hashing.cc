#include <bits/stdc++.h>

using namespace std;
using uint64 = unsigned long long;

int L;
string s;
uint64 MOD = 12'3456'7891;
uint64 R = 31;

int main()
{
	cin >> L >> s;

	uint64 H = 0;

	for (int i = 0; i < L; i++)
	{
		uint64 temp = static_cast<uint64>(s[i] - 'a' + 1);
		for (int j = 0; j < i; j++)
		{
			temp *= R;
			temp %= MOD;
		}
		H = ((H % MOD) + temp) % MOD;
	}

	cout << H << endl;

	return 0;
}
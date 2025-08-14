#include <bits/stdc++.h>

using namespace std;


int main()
{
	int N;
	int cnt = 0, i = 666;
	cin >> N;

	while(cnt != N)
	{
		int digit = 0;
		int num[10] = { 0, };
		int movie = i;

		while (i != 0)
		{
			int remainder = i % 10;
			num[digit++] = remainder;
			i /= 10;
		}

		i = movie;
		i++;
		for (int j = 0; j < digit; j++)
		{
			if ((num[j] == 6) && (num[j + 1] == 6) && (num[j + 2] == 6))
			{
				cnt++;
				break;
			}
		}

		if (cnt == N)
		{
			cout << movie << endl;
			break;
		}
	}

	return 0;
}
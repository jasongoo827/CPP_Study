#include <bits/stdc++.h>

using namespace std;

int N, num;
int a, b, c, d;
int sum = 0;
vector<int> v1;
//vector<pair<int, int>> most;
//vector<pair<int, int>> most2;
int cnt[8001] = { 0, };

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
}


int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		sum += num;
		v1.push_back(num);
		cnt[num + 4000]++;
	}

	a = static_cast<int>(round(static_cast<double>(sum) / N));
	//산술 평균
	if (a == -0)
	{
		a = 0;
	}

	//중앙값
	sort(v1.begin(), v1.end());
	b = v1[(N - 1) / 2];

	//최빈값
	//for (int i = 0; i <= 8000; i++)
	//{
	//	if (cnt[i] == 0) continue;
	//	most.push_back(make_pair(i, cnt[i]));
	//}
	//sort(most.begin(), most.end(), cmp);

	//for (auto it = most.begin(); it != most.end(); ++it)
	//{
	//	if (it->second == (--most.end())->second)
	//	{
	//		most2.push_back(make_pair(it->first, it->second));
	//	}
	//}

	//if (most2.size() <= 1)
	//{
	//	c = (--most2.end())->first - 4000;
	//}
	//else
	//{
	//	c = most2[1].first - 4000;
	//}

	int flag;
	int max = 0;

	for (int i = 0; i <= 8000; i++)
	{
		if (cnt[i] > max)
		{
			max = cnt[i];
			flag = i;
		}
	}

	for (int i = flag + 1; i <= 8000; i++)
	{
		if (cnt[i] == max)
		{
			flag = i;
			break;
		}
	}

	c = flag - 4000;

	//범위
	d = v1[N - 1] - v1[0];

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;

	return 0;
}
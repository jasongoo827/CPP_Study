#include <bits/stdc++.h>

using namespace std;


int main()
{
	int c, N, M;
	vector<int> v;
	queue<pair<int, int>> q;
	cin >> c;

	while (c--)
	{
		cin >> N >> M;
		for (int i = 0; i < N; i++)
		{
			int num;
			cin >> num;
			v.push_back(num);
			q.push(make_pair(i, num));
		}

		int cnt = 1;
		sort(v.rbegin(), v.rend());
		while (true)
		{
			if (q.front().second < (*v.begin()))
			{
				pair<int, int> p = q.front();
				q.pop();
				q.push(p);
			}
			else
			{
				if (q.front().first == M)
				{
					cout << cnt << endl;
					v.clear();
					while (!q.empty()) q.pop();
					break;
				}
				q.pop();
				v.erase(v.begin());
				cnt++;
			}
		}

	}
	
	return 0;
}
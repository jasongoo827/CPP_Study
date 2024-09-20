#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, score;
string name;
vector<pair<string, int> > v;

bool cmp(pair<string, int>& p1, pair<string, int>& p2)
{
	return p1.second < p2.second;
}

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> name >> score;
		v.push_back(make_pair(name, score));
	}
	sort(v.begin(), v.end(), cmp);
	for (auto& i: v)
	{
		cout << i.first << ' ';
	}
}
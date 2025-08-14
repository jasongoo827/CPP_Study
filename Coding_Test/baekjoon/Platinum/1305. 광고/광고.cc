#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L;
string s;
vector<int> table;

void createTable(const string& pattern)
{
	int n = static_cast<int>(pattern.size());
	int j = 0;

	for (int i = 1; i < n; ++i)
	{
		while (j > 0 && pattern[i] != pattern[j])
			j = table[j - 1];
		if (pattern[i] == pattern[j])
		{
			j++;
			table[i] = j;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> L >> s;
	table.assign(L, 0);

	createTable(s);
	cout << L - table[L - 1];
	
	return 0;
}
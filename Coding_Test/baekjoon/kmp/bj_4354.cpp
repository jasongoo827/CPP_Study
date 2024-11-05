#include <iostream>
#include <vector>

using namespace std;

string s;
vector<int> table;

// 최소 단위 길이
void createTable(const string& pattern)
{
	int n = static_cast<int>(pattern.size());
	int j = 0;

	for (int i = 1; i < n; ++i)
	{
		while (j > 0 && pattern[i] != pattern[j])
			j = table[j - 1];
		if (pattern[i] == pattern[j])
			table[i] = ++j;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (cin >> s)
	{
		if (s == ".")
			break;
		int len = static_cast<int>(s.length());
		table.assign(len, 0);
		createTable(s);
		int minRepLen = len - table[len - 1];
		if (len % minRepLen != 0)
			cout << "1\n";
		else
			cout << len / minRepLen << '\n';
	}
}
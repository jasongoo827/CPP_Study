#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;

vector<int> table;

void input(string& s)
{
	for (int i = 0; i < n; ++i)
	{
		char c;
		cin >> c;
		s += c;
	}
}

void createTable(const string& pattern)
{
	int n = static_cast<int>(pattern.length());
	int j = 0;

	for (int i = 1; i < n; ++i)
	{
		while (j > 0 && pattern[i] != pattern[j])
			j = table[j - 1];
		if (pattern[i] == pattern[j])
			table[i] = ++j;
	}
}

int kmpSearch(const string& text, const string& pattern)
{
	int n = static_cast<int>(text.length());
	int m = static_cast<int>(pattern.length());
	int j = 0;
	int cnt = 0;

	for (int i = 0; i < n; ++i)
	{
		while (j > 0 && text[i] != pattern[j])
			j = table[j - 1];
		if (text[i] == pattern[j])
		{
			if (j == m - 1)
			{
				cnt++;
				j = table[j];
			}
			else
				j++;
		}
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	string pattern, text;
	input(pattern);
	input(text);

	table.assign(pattern.length(), 0);
	text += text;
	text.pop_back();

	createTable(pattern);
	int ret = kmpSearch(text, pattern);
	while (ret != 1 && n % ret == 0)
	{
		n /= ret;
		ret /= ret;
	}
	cout << ret << "/" << n;

	return 0;
}

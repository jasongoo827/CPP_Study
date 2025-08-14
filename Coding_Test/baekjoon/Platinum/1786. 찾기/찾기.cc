#include <iostream>
#include <vector>
#include <string>

using namespace std;

string t, p;

vector<int> createPartialTable(const string& pattern)
{
	int n = static_cast<int>(pattern.size());

	vector<int> table(n, 0);
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
	return table;
}

vector<int> kmpSearch(const string& text, const string& pattern)
{
	vector<int> table = createPartialTable(pattern);
	vector<int> ret;
	int n = static_cast<int>(text.size());
	int m = static_cast<int>(pattern.size());
	int j = 0;

	for (int i = 0; i < n; ++i)
	{
		while (j > 0 && text[i] != pattern[j])
			j = table[j - 1];
		if (text[i] == pattern[j])
		{
			if (j == m - 1)
			{
				ret.push_back(i - j + 1);
				j = table[j];
			}
			else
				j++;
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	getline(cin, t);
	getline(cin, p);
	
	vector<int> ret = kmpSearch(t, p);
	cout << ret.size() << '\n';
	for (auto& i: ret)
		cout << i << " ";
}
#include <iostream>

using namespace std;

// boj 1515

string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;

    int n = 1;
    size_t pos = 0;

    while (pos < s.length())
    {
        string cmp = to_string(n);

        for (char c: cmp)
        {
            if (pos < s.length() && c == s[pos])
                pos++;
        }
        n++;
    }

    cout << n - 1 << '\n';

    return 0;
}
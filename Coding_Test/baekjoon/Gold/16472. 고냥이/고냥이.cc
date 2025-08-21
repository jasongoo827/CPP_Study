#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    string s;
    
    cin >> n >> s;
    
    int l = 0;
    int r = 0;
    int len = s.length();
    int type = 0;
    int alph[26] = {0};
    int maxLen = 0;
    
    while (r < len)
    {
        if (alph[s[r] - 'a']++ == 0)
            type++;
        while (type > n)
        {
            if (--alph[s[l] - 'a'] == 0)
                type--;
            l++;
        }
        maxLen = max(maxLen, r - l + 1);
        r++;
    }
    cout << maxLen << '\n';
    
    return 0;
}
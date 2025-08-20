#include <iostream>
#include <vector>

using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        
        int l = 0;
        int r = s.length() - 1;
        while (l < r && s[l] == s[r])
        {
            l++;
            r--;
        }
        if (l >= r)
        {
            cout << 0 << '\n';
            continue;
        }
        
        int l1 = l + 1;
        int r1 = r;
        while (l1 < r1 && s[l1] == s[r1])
        {
            l1++;
            r1--;
        }
        if (l1 >= r1)
        {
            cout << 1 << '\n';
            continue;
        }
        
        int l2 = l;
        int r2 = r - 1;
        while (l2 < r2 && s[l2] == s[r2])
        {
            l2++;
            r2--;
        }
        if (l2 >= r2)
        {
            cout << 1 << '\n';
            continue;
        }
        
        cout << 2 << '\n';
    }
    
    return 0;
}
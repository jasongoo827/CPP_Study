#include <iostream>
#include <algorithm>

using namespace std;

string s, t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> s >> t;
    
    while (s.length() != t.length())
    {
        if (t[t.length() - 1] == 'A')
            t.pop_back();
        else
        {
            t.pop_back();
            reverse(t.begin(), t.end());
        }
    }
    
    if (s != t)
        cout << 0 << '\n';
    else
        cout << 1 << '\n';
    
    return 0;
}
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    
    int a_count = 0;
    int b_count = 0;
    
    for (char c: s)
        if (c == 'a')
            a_count++;
    
    for (int i = 0; i < a_count; ++i)
    {
        if (s[i] == 'b')
            b_count++;
    }
    
    int min_swap = b_count;
    int n = s.length();
    for (int i = 1; i < n; ++i)
    {
        if (s[i - 1] == 'b')
            b_count--;
        if (s[(i + a_count - 1) % n] == 'b')
            b_count++;
        min_swap = min(min_swap, b_count);
    }
    cout << min_swap << '\n';
    
    return 0;
}
#include <iostream>

using namespace std;

string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> s;
    
    int sum = 0;
    int k;
    for (int i = 0; i < 12; ++i)
    {
        if (s[i] == '*')
        {
            k = (i % 2 == 0) ? 1 : 3;
            continue;
        }
        else if (i % 2 == 0)
            sum += (s[i] - '0');
        else
            sum += (s[i] - '0') * 3;
    }
    
    int m = s[s.length() - 1] - '0';
    
    for (int i = 0; i < 10; ++i)
    {   
        if ((sum + k * i + m) % 10 == 0)
        {
            cout << i << '\n';
            break;
        }
    }
    
    return 0;
}

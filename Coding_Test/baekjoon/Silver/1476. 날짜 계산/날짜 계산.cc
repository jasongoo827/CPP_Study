#include <iostream>

using namespace std;

// boj 1476

int e, s, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> e >> s >> m;
    
    int year = 1;
    while (true)
    {
        if (((year - 1) % 15 + 1 == e) && ((year - 1) % 28  + 1 == s) && ((year - 1) % 19 + 1 == m))
            break;
        year++;
    }
    cout << year << '\n';

    return 0;
}
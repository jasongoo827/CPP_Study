#include <iostream>

using namespace std;
using ll = long long;

// boj 16953

int a, b;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b;

    int count = 1;
    while (b > a)
    {
        if (b % 2 == 0)
            b /= 2;
        else if (b % 10 == 1)
            b /= 10;
        else
            break;
        count++;
    }

    cout << (b == a ? count : -1) << '\n';

    return 0;
}
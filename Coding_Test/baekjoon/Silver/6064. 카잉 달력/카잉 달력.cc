#include <iostream>

using namespace std;

// boj 6064

int t;
int m, n, x, y;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--)
    {
        int year = 1;
        bool flag = true;
        cin >> m >> n >> x >> y;
        for (int year = x; year <= lcm(m, n); year += m)
        {
            if ((year - 1) % n + 1 == y)
            {
                cout << year << '\n';
                flag = false;
                break;
            }
        }
        if (flag)
            cout << -1 << '\n';
    }

    return 0;
}
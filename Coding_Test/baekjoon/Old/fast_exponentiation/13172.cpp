#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;

// boj 13172

int m;
const int MOD = 1000000007;

ll power(ll base, ll exp, ll mod)
{
    ll ret = 1;

    while (exp > 0)
    {
        if (exp % 2 == 1)
            ret = (ret * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return ret;
}

int gcd(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m;
    ll sum = 0;
    for (int i = 0; i < m; ++i)
    {
        int n, s;
        cin >> n >> s;

        int t = gcd(n, s);
        int a = s / t;
        int b = n / t;

        ll ret = power(b, MOD - 2, MOD);
        ret = (ret * a) % MOD;
        sum = (sum + ret) % MOD;
    }
    cout << sum << '\n';

    return 0;
}
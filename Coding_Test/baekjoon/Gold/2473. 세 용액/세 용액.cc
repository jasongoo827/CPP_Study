#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

// boj 2473

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    vector<ll> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());

    int ret1, ret2, ret3;
    ll best = 3e9 + 1;
    
    for (int i = 0; i < n - 2; ++i)
    {
        int l = i + 1;
        int r = n - 1;

        while (l < r)
        {
            ll sum = v[i] + v[l] + v[r];
            ll abs_sum = abs(sum);
            if (abs_sum < best)
            {
                best = abs_sum;
                ret1 = v[i];
                ret2 = v[l];
                ret3 = v[r];
            }
            if (sum == 0)
            {
                cout << ret1 << " " << ret2 << " " << ret3 << '\n';
                return 0;
            }
            else if (sum > 0)
                r--;
            else
                l++;
        }
    }
    cout << ret1 << " " << ret2 << " " << ret3 << '\n';

    return 0;
}
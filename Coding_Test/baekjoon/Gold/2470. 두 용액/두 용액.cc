#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    sort(v.begin(), v.end());
    
    int l = 0;
    int r = n - 1;
    int best = 2e9;
    int ret1 = v[l];
    int ret2 = v[r];
    
    while (l < r)
    {
        int sum = v[l] + v[r];
        int abs_sum = abs(sum);
        if (abs_sum < best)
        {
            best = abs_sum;
            ret1 = v[l];
            ret2 = v[r];
        }
        if (sum < 0)
            l++;
        else
            r--;
    }
    
    cout << ret1 << " " << ret2 << '\n';
    
    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    vector<int> v(n);
    
    for (int i = 0; i < n; ++i)
        cin >> v[i];

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
        else if (abs_sum == 0)
        {
            cout << v[l] << " " << v[r] << '\n';
            return 0;
        }
        if (sum > 0)
            r--;
        else
            l++;
    }
    cout << ret1 << " " << ret2 << '\n';
    
    return 0;
}

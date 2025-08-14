#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> k;
    
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    int l = 0;
    int r = 0;
    int ret = INT_MIN;
    int sum = 0;
    
    while (true)
    {
        if (r - l == k)
        {
            ret = max(ret, sum);
            sum -= v[l++];
        }
        if (r == n)
            break;
        sum += v[r++];
    }
    cout << ret << '\n';
    
    return 0;
}
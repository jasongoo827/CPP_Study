#include <iostream>
#include <vector>

using namespace std;

int n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> k;
    
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    int ret = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        int cnt = k / v[i];
        if (cnt != 0)
        {
            ret += cnt;
            k %= v[i];
            if (k == 0)
                break;
        }
    }
    cout << ret << '\n';
    
    return 0;
}
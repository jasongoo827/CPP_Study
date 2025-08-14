#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    
    vector<int> v(n);

    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());
    
    int ret = 0;
    for (int i = 0; i < n; ++i)
    {
        int maxVal = v[i] * (n - i);
        ret = max(ret, maxVal);
    }
    cout << ret << '\n';
    
    return 0;
}

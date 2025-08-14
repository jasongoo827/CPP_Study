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
    vector<int> sum(n);
    
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    sort(v.begin(), v.end());

    sum[0] = v[0];
    for (int i = 1; i < n; ++i)
        sum[i] = sum[i - 1] + v[i];
    
    int ret = 0;
    for (int s: sum)
        ret += s;
    cout << ret << '\n';
    
    return 0;
}
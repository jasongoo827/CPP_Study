#include <iostream>
#include <vector>

using namespace std;

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    
    vector<int> v(n + 1);
    vector<int> prefix(n + 1);
    
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    
    prefix[0] = 0;
    for (int i = 1; i <= n; ++i)
        prefix[i] = prefix[i - 1] + v[i];
    
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << '\n';
    }
    
    return 0;
}

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

    vector<int> sorted = v;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    for (int i = 0; i < n; ++i)
    {
        int idx = lower_bound(sorted.begin(), sorted.end(), v[i]) - sorted.begin();
        cout << idx;
        if (i != n - 1) cout << ' ';
    }

    return 0;
}

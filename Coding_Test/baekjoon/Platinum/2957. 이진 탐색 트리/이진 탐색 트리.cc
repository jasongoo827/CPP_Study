#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int n, x;
map<int, int> tree;
long long ret = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    tree.insert({0, -1});
    tree.insert({300001, -1});
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        auto upper = tree.upper_bound(x);
        auto lower = upper--;
        int val = max(upper->second, lower->second) + 1;
        tree.insert({x, val});
        ret += val;
        cout << ret << '\n';
    }
}
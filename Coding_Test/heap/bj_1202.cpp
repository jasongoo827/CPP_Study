#include <iostream>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int n, k;
priority_queue<pair<int,int>> pq;
multiset<int> vt;

void input()
{
    cin >> n >> k;

    int m, v;
    for (int i = 0; i < n; ++i)
    {
        cin >> m >> v;
        pq.push(make_pair(v,m));
    }

    int c;
    for (int i = 0; i < k; ++i)
    {
        cin >> c;
        vt.insert(c);
    }
}

void solve()
{
    long long ret = 0;
    int i = 0;

    while (!vt.empty())
    {
        if (pq.empty()) break;
        pair<int,int> top = pq.top();
        pq.pop();
        auto low = vt.lower_bound(top.second);

        if (low == vt.end()) 
            continue;
        else
            vt.erase(low);
        ret += top.first;
    }
    cout << ret;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve();

    return (0);
}
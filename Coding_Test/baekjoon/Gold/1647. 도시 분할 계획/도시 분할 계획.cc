#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// boj 1647
using node = pair<int, pair<int, int>>;
vector<int> parent;

int n, m;

int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
	{
		if (a < b)
			parent[b] = a;
		else
			parent[a] = b;
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    priority_queue<node, vector<node>, greater<node>> pq;
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({c, {a, b}});
    }
    
    parent.resize(n + 1);
    for (int i = 1; i <= n; ++i)
        parent[i] = i;

    int edge = 0;
    int mstWeight = 0;
    while (edge < n - 2)
    {
        int cost = pq.top().first;
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        pq.pop();

        if (find(u) != find(v))
        {
            merge(u, v);
            edge++;
            mstWeight += cost;
        }
    }

    cout << mstWeight << '\n';

    return 0;
}
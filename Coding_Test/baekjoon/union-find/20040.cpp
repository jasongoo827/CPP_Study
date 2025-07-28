#include <iostream>

using namespace std;

// boj 20040

int n, m;
int parent[500001];

int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

bool merge(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a == b)
        return false;

    if (a > b)
        parent[a] = b;
    else
        parent[b] = a;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        parent[i] = i;

    int ret = 1;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;

        if (!merge(a, b))
        {
            cout << ret << '\n';
            return 0;
        }
        ret++;
    }
    cout << 0 << '\n';

    return 0;
}
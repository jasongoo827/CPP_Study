#include <iostream>
#define MAX 201

using namespace std;

int n, m;
int parent[MAX];

int get_parent(int x)
{
    if (parent[x] == x) return x;
    return parent[x] = get_parent(parent[x]);
}

void union_parent(int a, int b)
{
    a = get_parent(a);
    b = get_parent(b);
    if (a > b)
        parent[a] = b;
    else
        parent[b] = a;
}

void solve()
{
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        parent[i] = i;
    
    int info;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> info;
            if (info == 1)
                union_parent(i, j);
        }
    }

    int city, root;
    for (int i = 0; i < m; ++i)
    {
        cin >> city;
        if (i == 0)
            root = get_parent(city);
        else
        {
            if (root != get_parent(city))
            {
                cout << "NO";
                return;
            }
        }
    }
    cout << "YES";
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return (0);
}
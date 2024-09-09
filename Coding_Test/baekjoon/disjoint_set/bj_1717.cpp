#include <iostream>
#define MAX 1000001
#define endl '\n'

using namespace std;

int n, m;
int parent[MAX];

int get_parent(int x)
{
    if (parent[x] == x) return x;
    return parent[x] = get_parent(parent[x]);
}

void find_parent(int a, int b)
{
    a = get_parent(a);
    b = get_parent(b);
    if (a == b)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        parent[i] = i;
    
    while (m--)
    {
        int a, b, c;
        cin >> c >> a >> b;
        if (!c)
            union_parent(a, b);
        else
            find_parent(a, b);
    }

    return (0);
}
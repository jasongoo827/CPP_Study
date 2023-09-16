#include <iostream>
#define MAX 51

using namespace std;

int n, m, t;
int parent[MAX];
int party_roots[MAX];

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

    cin >> t;
    int per, root = 0;
    for (int i = 0; i < t; ++i)
    {
        cin >> per;
        if (i == 0)
            root = parent[per];
        else
            parent[per] = root;
    }

    int party_people, ret = 0;
    for (int j = 0; j < m; ++j)
    {
        cin >> party_people;
        int party_per, party_root = 0;
        for (int i = 0; i < party_people; ++i)
        {
            cin >> party_per;
            if (i == 0)
                party_root = parent[party_per];
            else
            {
                if (get_parent(party_per) == root && root > party_root) root = party_root;
                union_parent(party_root, party_per);
            }
        }
        party_roots[j] = get_parent(party_root);
    }

    for (int i = 0; i < m; ++i)
    {
        if (party_roots[i] != root && get_parent(party_roots[i]) != root) ret++;
    }
    cout << ret;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    solve();
    return (0);
}
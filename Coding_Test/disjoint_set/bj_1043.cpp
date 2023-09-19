#include <iostream>
#include <vector>
#define MAX 51

using namespace std;

int n, m, t;
int parent[MAX];
int party_roots[MAX];
vector<int> know;

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
        know.push_back(per);
    }

    int party_people;
    for (int i = 0; i < m; ++i)
    {
        cin >> party_people;
        int party_per, party_root = 0;
        for (int j = 0; j < party_people; ++j)
        {
            cin >> party_per;
            if (j == 0)
                party_root = get_parent(party_per);
            else
                union_parent(party_root, party_per);
        }
        party_roots[i] = party_root;
    }

    int ret = m;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < (int)know.size(); ++j)
        {
            if (get_parent(party_roots[i]) == get_parent(know[j]))
            {
                ret--;
                break;
            }
        }
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
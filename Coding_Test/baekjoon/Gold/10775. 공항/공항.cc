#include <iostream>
#include <vector>

using namespace std;

// boj 10775

int g, p;
vector<int> parent;

int find(int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
    {
        if (a > b)
            parent[a] = b;
        else
            parent[b] = a;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> g >> p;
    parent.resize(g + 1);

    for (int i = 0; i <= g; ++i)
        parent[i] = i;

    int ret = 0;
    for (int i = 0; i < p; ++i)
    {
        int gi;
        cin >> gi;

        int gate = find(gi);
        if (gate != 0)
        {
            ret++;
            merge(gate, gate - 1);
        }
        else
            break;
    }
    cout << ret << '\n';

    return 0;
}
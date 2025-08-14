#include <iostream>

#define MAX 1000001

using namespace std;
typedef long long ll;

int n, m, k;
ll arr[MAX];
ll tree[MAX * 4], lazy[MAX * 4];

ll init(int start, int end, int node)
{
    if (start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

void lazy_update(int start, int end, int node)
{
    if (lazy[node] != 0)
    {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end)
        {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int start, int end, int node, int left, int right, ll value)
{
    lazy_update(start, end, node);
    if (right < start || end < left) return;
    if (left <= start && end <= right)
    {
        lazy[node] += value;
        lazy_update(start, end, node);
        return;
    }
    int mid = (start + end) / 2;
    update(start, mid, node * 2, left, right, value);
    update(mid + 1, end, node * 2 + 1, left, right, value);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int start, int end, int node, int left, int right)
{
    lazy_update(start, end, node);
    if (right < start || end < left) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    init(1, n, 1);

    int i = 0, j = 0;
    while (1)
    {
        if (i == m && j == k)
            break;
        int a, b, c;
        ll d;
        cin >> a >> b >> c;
        if (a == 1)
        {
            cin >> d;
            update(1, n, 1, b, c, d);
            i++;
        }
        else if (a == 2)
        {
            cout << query(1, n, 1, b, c) << '\n';
            j++;
        }
    }
}
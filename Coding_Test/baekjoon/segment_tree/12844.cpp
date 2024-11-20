#include <iostream>

#define MAX 500001

using namespace std;
typedef long long ll;

int n, m;
int arr[MAX];
int tree[MAX * 4], lazy[MAX * 4];

int init(int start, int end, int node)
{
    if (start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) ^ init(mid + 1, end, node * 2 + 1);
}

void lazy_update(int start, int end, int node)
{
    if (lazy[node] != 0)
    {
        if ((end - start + 1) & 1)
            tree[node] ^= lazy[node];
        if (start != end)
        {
            lazy[node * 2] ^= lazy[node];
            lazy[node * 2 + 1] ^= lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int start, int end, int node, int left, int right, int k)
{
    lazy_update(start, end, node);
    if (right < start || end < left) return;
    if (left <= start && end <= right)
    {
        lazy[node] ^= k;
        lazy_update(start, end, node);
        return;
    }
    int mid = (start + end) / 2;
    update(start, mid, node * 2, left, right, k);
    update(mid + 1, end, node * 2 + 1, left, right, k);
    tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

int query(int start, int end, int node, int left, int right)
{
    lazy_update(start, end, node);
    if (right < start || end < left) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return query(start, mid, node * 2, left, right) ^ query(mid + 1, end, node * 2 + 1, left, right);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    init(1, n, 1);
    
    cin >> m;
    for (int x = 0; x < m; ++x)
    {
        int q, i, j, k;
        cin >> q >> i >> j;
        if (q == 1)
        {
            cin >> k;
            update(1, n, 1, i + 1, j + 1, k);
        }
        else if (q == 2)
            cout << query(1, n, 1, i + 1, j + 1) << '\n';
    }
}
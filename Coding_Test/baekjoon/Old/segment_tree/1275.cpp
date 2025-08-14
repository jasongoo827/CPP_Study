#include <iostream>

#define MAX 100001
typedef long long ll;

using namespace std;

int n, q;
int arr[MAX];
ll tree[MAX * 4];

ll init(int start, int end, int node)
{
    if (start == end)
        return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

void update(int start, int end, int node, int idx, ll diff)
{
    if (idx < start || idx > end) return;
    tree[node] += diff;
    if (start == end) return;
    int mid = (start + end) / 2;
    update(start, mid, node * 2, idx, diff);
    update(mid + 1, end, node * 2 + 1, idx, diff);
}

ll query(int start, int end, int node, int left, int right)
{
    if (right < start || end < left)
        return 0;
    if (left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;
    ll lQuery = query(start, mid, node * 2, left, right);
    ll rQuery = query(mid + 1, end, node * 2 + 1, left, right);

    return (lQuery + rQuery);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    init(1, n, 1);

    for (int i = 0; i < q; ++i)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if (x > y) swap(x, y);
        cout << query(1, n, 1, x, y) << "\n";
        update(1, n, 1, a, static_cast<ll>(b) - arr[a]);
        arr[a] = b;
    }
}
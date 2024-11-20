#include <iostream>

#define MAX 1000001
#define MOD 1000000007
typedef long long ll;

using namespace std;

int n, m, k;
int arr[MAX];
ll tree[MAX * 4];

ll init(int start, int end, int node)
{
    if (start == end)
        return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = (init(start, mid, node * 2) * init(mid + 1, end, node * 2 + 1)) % MOD;
}

ll update(int start, int end, int node, int idx, int value)
{
    if (idx < start || idx > end) return tree[node];
    if (start == end)
        return tree[node] = value;
    int mid = (start + end) / 2;

    ll left = update(start, mid, node * 2, idx, value);
    ll right = update(mid + 1, end, node * 2 + 1, idx, value);

    return tree[node] = (left * right) % MOD;
}

ll query(int start, int end, int node, int left, int right)
{
    if (right < start || end < left)
        return 1;
    if (left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;

    ll lQuery = query(start, mid, node * 2, left, right);
    ll rQuery = query(mid + 1, end, node * 2 + 1, left, right);

    return (lQuery * rQuery) % MOD;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; ++i)
        cin >> arr[i];

    init(1, n, 1);
    for (int i = 0; i < m + k; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
            update(1, n, 1, b, c);
        else if (a == 2)
            cout << query(1, n, 1, b, c) << '\n';
    }
}
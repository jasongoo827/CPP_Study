#include <iostream>
#define MAX 1000000
#define endl '\n'

using namespace std;

int n, m, k;
long long arr[MAX];
long long tree[MAX * 4];

long long init(int start, int end, int node)
{
    if (start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

long long sum(int start, int end, int node, int left, int right)
{
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, long long diff)
{
    if (index < start || index > end) return;
    tree[node] += diff;
    if (start == end) return;
    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, diff);
    update(mid + 1, end, node * 2 + 1, index, diff);
}

void input()
{
    long long a, b, c;

    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    
    init(0, n - 1, 1);
    for (int j = 0; j < m + k; ++j)
    {
        cin >> a >> b >> c;
        if (a == 1)
        {
            long long diff = c - arr[b - 1];
            arr[b - 1] = c;
            update(0, n - 1, 1, b - 1, diff);
        }
        else if (a == 2)
            cout << sum(0, n - 1, 1, b - 1, c - 1) << endl;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;

    input();

    return (0);
}
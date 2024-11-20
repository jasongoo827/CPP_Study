#include <iostream>
#include <algorithm>

#define MAX 100001
#define M 1000000001

using namespace std;

int n, m;

int arr[MAX];
int min_tree[MAX * 4];

int init_min(int start, int end, int node)
{
    if (start == end) return min_tree[node] = arr[start];
    int mid = (start + end) / 2;
    return min_tree[node] = min(init_min(start, mid, node * 2), init_min(mid + 1, end, node * 2 + 1));
}

int query_min(int start, int end, int node, int left, int right)
{
    if (right < start || end < left) return M;
    if (left <= start && end <= right)
        return min_tree[node];
    int mid = (start + end) / 2;
    return min(query_min(start, mid, node * 2, left, right), query_min(mid + 1, end, node * 2 + 1, left, right));
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    
    fill_n(min_tree, n + 1, M);
    init_min(1, n, 1);
    
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        cout << query_min(1, n, 1, a, b) << '\n';
    }
}
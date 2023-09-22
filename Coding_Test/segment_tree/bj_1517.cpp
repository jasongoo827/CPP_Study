#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int>> arr;
vector<int> tree;
int n;

int init(int start, int end, int node)
{
    if (start == end) return tree[node] = 1;
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

int sum(int start, int end, int left, int right, int node)
{
    if (right < start || left > end) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(start, mid, left, right, node * 2) + sum(mid + 1, end, left, right, node * 2 + 1);
}

void update(int start, int end, int node, int index, int val)
{
    if (index < start || index > end) return;
    if (start == end)
    {
        if (start == index)
            tree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, val);
    update(mid + 1, end, node * 2 + 1, index, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void input()
{
    cin >> n;

    int input;
    for (int i = 0; i < n; ++i)
    {
        cin >> input;
        arr.push_back(make_pair(input, i));
    }
    int h = (int)ceil(log2(n));
    int size = (1 << h) + 1;
    tree.resize(size);
}

void solve()
{
    init(0, n - 1, 1);
    sort(arr.begin(), arr.end());

    long long ret = 0;
    for (int i = 0; i < n; ++i)
    {
        int index = arr[i].second;
        ret += sum(0, n - 1, 0, index, 1) - 1;
        update(0, n - 1, 1, index, 0);
    }
    cout << ret;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();

    return (0);
}
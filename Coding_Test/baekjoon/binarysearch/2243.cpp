#include <iostream>

#define MAX 1000000

using namespace std;


int n;
int tree[MAX * 4] = {0,};

void update(int start, int end, int node, int idx, int diff)
{
    if (idx < start || idx > end) return;
    tree[node] += diff;
    if (start == end) return;
    int mid = (start + end) / 2;
    update(start, mid, node * 2, idx, diff);
    update(mid + 1, end, node * 2 + 1, idx, diff);
}

int query(int start, int end, int node, int k)
{
    if (start == end) return start;
    int mid = (start + end) / 2;
    if (tree[node * 2] >= k)
        return query(start, mid, node * 2, k);
    else
        return query(mid + 1, end, node * 2 + 1, k - tree[node * 2]);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    
    while (n--)
    {
        int a, b, c;
        cin >> a;
        if (a == 1)
        {
            cin >> b;
            int taste = query(1, MAX, 1, b);
            cout << taste << '\n';
            update(1, MAX, 1, taste, -1);
        }
        else if (a == 2)
        {
            cin >> b >> c;
            update(1, MAX, 1, b, c);
        }
    }
}
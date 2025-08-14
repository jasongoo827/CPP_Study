#include <iostream>

#define MAX 5000001
typedef long long ll;

using namespace std;

int n;
int a[MAX], b[MAX];
int tree[MAX], chk[MAX];

int sum(int i)
{
    int ret = 0;
    while (i > 0)
    {
        ret += tree[i];
        i -= (i & -i);
    }
    return ret;
}

void update(int i, int num, int size)
{
    while (i <= size)
    {
        tree[i] += num;
        i += (i & -i);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        chk[a[i]] = i;
    }

    ll ret = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
        ret += static_cast<ll>(sum(n)) - static_cast<ll>(sum(chk[b[i]]));
        update(chk[b[i]], 1, n);
    }
    cout << ret << '\n';
}
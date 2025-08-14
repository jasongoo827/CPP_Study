#include <iostream>
#include <stack>
#include <string.h>
#define MAX 500001

using namespace std;

int n;
int top[MAX];
int res[MAX];
stack<pair<int, int>> s;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> top[i];
    memset(res, 0, sizeof(res));
}

void solve()
{
    for (int i = 0 ; i < n; ++i)
    {
        while (!s.empty() && s.top().first <= top[i])
            s.pop();
        if (s.empty())
            res[i] = 0;
        else
            res[i] = s.top().second;
        s.push(make_pair(top[i], i + 1));
    }
    for (int i = 0 ; i < n; ++i)
        cout << res[i] << " ";
}

int main(void)
{
    input();
    solve();
    
    return (0);
}
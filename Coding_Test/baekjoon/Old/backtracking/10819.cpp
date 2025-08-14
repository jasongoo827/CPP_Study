#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// boj 10819

int n;
bool visited[9];
int ret = INT_MIN;

void dfs(int picked, vector<int>& v, vector<int>& a)
{
    if (picked == n)
    {
        int sum = 0;
        for (int i = 1; i < n; ++i)
            sum += abs(a[v[i]] - a[v[i - 1]]);
        ret = max(ret, sum);
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            visited[i] = true;
            v.push_back(i);
            dfs(picked + 1, v, a);
            v.pop_back();
            visited[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<int> v;
    dfs(0, v, a);

    cout << ret << '\n';

    return 0;
}
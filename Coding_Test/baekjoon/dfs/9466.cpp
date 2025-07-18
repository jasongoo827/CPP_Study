#include <iostream>
#include <vector>

using namespace std;

// boj 9466 - 유향 그래프 사이클 판별

int t, n;
int team = 0;

void dfs(int node, vector<int>& wanted, vector<int>& visited)
{
    if (visited[node] == 1)
    {
        int next = wanted[node];
        int cycle = 1;

        while (next != node)
        {
            cycle++;
            next = wanted[next];    
        }
        team += cycle;
        return;
    }
    if (visited[node] == 2)
        return;
    
    visited[node] = 1;
    dfs(wanted[node], wanted, visited);
    visited[node] = 2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> v(n + 1);
        vector<int> visited(n + 1, 0);
        team = 0;

        for (int i = 1; i <= n; ++i)
            cin >> v[i];
        for (int i = 1; i <= n; ++i)
        {
            if (!visited[i])
                dfs(i, v, visited);
        }
        cout << n - team << '\n';
    }

    return 0;
}
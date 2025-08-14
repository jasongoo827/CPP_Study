#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 20001

int k;

bool dfs(int v, int c, vector<vector<int>>& graph, vector<int>& color)
{
    color[v] = c;

    for (size_t i = 0; i < graph[v].size(); ++i)
    {
        int node = graph[v][i];
        if (color[node] == -1)
        {
            if (!dfs(node, 1 - c, graph, color))
                return false;
        }
        else if (color[node] == c)
            return false;
    }
    return true;
}

bool isBipartite(vector<vector<int> >& graph, int n)
{
    vector<int> color(n + 1, -1);

    for (int i = 1; i <= n; ++i)
    {
        if (color[i] == -1)
        {
            if (!dfs(i, 0, graph, color))
                return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;

    cin >> k;
    while (k--)
    {
        int v, e;

        cin >> v >> e;
        vector<vector<int>> graph(v + 1);

        for (int i = 0; i < e; ++i)
        {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        if (isBipartite(graph, v))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
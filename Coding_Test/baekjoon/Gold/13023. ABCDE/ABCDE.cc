#include <iostream>
#include <vector>

using namespace std;

int n, m;

bool dfs(vector<vector<int>>& graph, vector<bool>& visited, int start, int depth)
{
    if (depth == 4)
        return true;
    
    visited[start] = true;
    for (int i = 0; i < graph[start].size(); ++i)
    {
        int next = graph[start][i];
        if (!visited[next])
        {
            if (dfs(graph, visited, next, depth + 1))
                return true;
        }
    }
    visited[start] = false;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>());
    
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for (int i = 0; i < n; ++i)
    {
        vector<bool> visited(n, false);
        if (dfs(graph, visited, i, 0))
        {
            cout << 1 << '\n';
            return 0;
        }
    }
    cout << 0 << '\n';
    
    return 0;
}
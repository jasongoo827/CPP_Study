#include <iostream>
#include <vector>

using namespace std;

// boj 15681 - 트리에서의 dp

int n, r, q;

int dfs(int node, int par, vector<vector<int>>& graph, vector<int>& size)
{
    size[node] = 1;
    for (int child: graph[node])
    {
        if (child != par)
            size[node] += dfs(child, node, graph, size);
    }
    return size[node];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> r >> q;
    vector<vector<int>> graph(n + 1, vector<int>());
    vector<int> size(n + 1, 0);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(r, -1, graph, size);
    for (int i = 0; i < q; ++i)
    {
        int node;
        cin >> node;
        cout << size[node] << '\n';
    }

    return 0;
}
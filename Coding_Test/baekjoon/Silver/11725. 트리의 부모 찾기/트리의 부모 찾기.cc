#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
const int MAX = 100001;
vector<int> graph[MAX];
bool visited[MAX];
int parent[MAX];

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for (int i = 0; i < graph[cur].size(); ++i)
        {
            int next = graph[cur][i];
            if (!visited[next])
            {
                visited[next] = true;
                parent[next] = cur;
                q.push(next);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
        
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bfs(1);
    
    for (int i = 2; i <= n; ++i)
        cout << parent[i] << '\n';
    
    return 0;
}

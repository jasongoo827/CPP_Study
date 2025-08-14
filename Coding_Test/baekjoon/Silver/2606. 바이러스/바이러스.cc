#include <iostream>
#include <vector>

using namespace std;

int n, p;
vector<int> graph[101];
bool visited[101];
int ret = 0;

void dfs(int start)
{
    visited[start] = true;
    
    for (int i = 0; i < graph[start].size(); ++i)
    {
        int next = graph[start][i];
        
        if (!visited[next])
        {
            dfs(next);
            ret++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> p;
    
    while (p--)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dfs(1);
    cout << ret << '\n';
    
    return 0;
}

#include <iostream>
#include <vector>
#include <queue>

#define MAX 1001

using namespace std;

int t, n, k;
int x, y, w;
int d[MAX];
int indegree[MAX];
int cost[MAX];
vector<int> graph[MAX];

void topological_sort()
{
    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    
    while (!q.empty())
    {
        int start = q.front();
        q.pop();
        
        for (int i = 0; i < graph[start].size(); ++i)
        {
            int next = graph[start][i];
            indegree[next]--;
            cost[next] = max(cost[next], cost[start] + d[next]);
            if (indegree[next] == 0)
                q.push(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i)
        {
            graph[i].clear();
            cin >> d[i];
            cost[i] = d[i];
        }
        fill(indegree + 1, indegree + n + 1, 0);
        for (int i = 0; i < k; ++i)
        {
            cin >> x >> y;
            graph[x].push_back(y);
            indegree[y]++;
        }
        cin >> w;
        topological_sort();
        cout << cost[w] << '\n';
    }
    
    return 0;
}
#include <iostream>
#include <queue>
#include <vector>
#define MAX 32001

using namespace std;

int n, m;
int indegree[MAX];
vector<int> graph[MAX];

void input()
{
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        indegree[i] = 0;

    int a, b;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        indegree[b]++;
        graph[a].push_back(b);
    }
}

void solve()
{
    priority_queue<int> pq;

    for (int i = 1; i <= n; ++i)
    {
        if (indegree[i] == 0)
            pq.push(-i);
    }

    while (!pq.empty())
    {
        int cur = -pq.top();
        cout << cur << " ";
        pq.pop();

        for (int i = 0; i < (int)graph[cur].size(); ++i)
        {
            int next = graph[cur][i];
            indegree[next]--;
            if (indegree[next] == 0)
                pq.push(-next);
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();

    return (0);
}
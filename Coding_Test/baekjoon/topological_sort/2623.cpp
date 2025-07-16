#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// boj 2623

int n, m;
int indegree[1001];
vector<int> graph[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        indegree[i] = 0;

    for (int i = 0; i < m; ++i)
    {
        int k;
        cin >> k;

        int prev, cur;
        for (int j = 0; j < k; ++j)
        {
            cin >> cur;
            if (j != 0)
            {
                indegree[cur]++;
                graph[prev].push_back(cur);
            }
            prev = cur;
        }
    }

    vector<int> ret;
    queue<int> q;

    for (int i = 1; i <= n; ++i)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int here = q.front();
        q.pop();
        ret.push_back(here);

        for (int i = 0; i < graph[here].size(); ++i)
        {
            int there = graph[here][i];
            indegree[there]--;

            if (indegree[there] == 0)
                q.push(there);
        }
    }

    if (ret.size() != n)
        cout << 0 << '\n';
    else
    {
        for (int num: ret)
            cout << num << '\n';
    }

    return 0;
}
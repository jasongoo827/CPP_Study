#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10001

using namespace std;

int v;
vector<vector<pair<int, int>>> graph(MAX);
vector<bool> visited(MAX, false);
int maxDist = 0;
int farthestNode = 0;

void dfs(int start, int dist)
{
    visited[start] = true;

    if (dist > maxDist)
    { 
        maxDist = dist;
        farthestNode = start;
    }

    for (auto& next : graph[start])
    {
        int nextNode = next.first;
        int weight = next.second;

        if (!visited[nextNode])
            dfs(nextNode, dist + weight);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> v;
    for (int i = 0; i < v - 1; ++i)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        graph[v1].push_back({v2, w});
        graph[v2].push_back({v1, w});
    }

    fill(visited.begin(), visited.begin() + v + 1, false);
    dfs(1, 0);

    fill(visited.begin(), visited.begin() + v + 1, false);
    maxDist = 0;
    dfs(farthestNode, 0);

    cout << maxDist << '\n';
}
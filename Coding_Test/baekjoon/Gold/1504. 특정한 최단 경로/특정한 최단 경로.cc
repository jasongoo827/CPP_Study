#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 200000001

const int MAX_V = 801;
vector<pair<int, int>> adj[MAX_V];
int dist[MAX_V];
int dist_v1[MAX_V];
int dist_v2[MAX_V];
int n, e, v1, v2;

void dijkstra(int start, int* d)
{
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    d[start] = 0;
    
    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        
        if (d[here] < cost)
            continue;
        for (int i = 0; i < adj[here].size(); ++i)
        {
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            
            if (d[there] > nextDist)
            {
                d[there] = nextDist;
                pq.push({-nextDist, there});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> e;
    
    for (int i = 0; i < e; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    cin >> v1 >> v2;
    
    fill(dist + 1, dist + n + 1, INF);
    fill(dist_v1 + 1, dist_v1 + n + 1, INF);
    fill(dist_v2 + 1, dist_v2 + n + 1, INF);
    
    dijkstra(1, dist);
    dijkstra(v1, dist_v1);
    dijkstra(v2, dist_v2);
    
    int path1 = dist[v1] + dist_v1[v2] + dist_v2[n];
    int path2 = dist[v2] + dist_v2[v1] + dist_v1[n];
    int ret = min(path1, path2);
    
    cout << (ret >= INF ?  -1 : ret);
    
    return 0;
}
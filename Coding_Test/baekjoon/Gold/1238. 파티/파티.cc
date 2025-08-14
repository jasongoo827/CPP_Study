#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_V = 1001;

int n, m, x;
vector<pair<int, int>> adj[MAX_V];
vector<pair<int, int>> rev_adj[MAX_V];

int dist[MAX_V];
int rev_dist[MAX_V];

void dijkstra(int start)
{
    priority_queue<pair<int, int>> pq;
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        
        if (dist[here] < cost)
            continue;
        
        for (int i = 0; i < adj[here].size(); ++i)
        {
            int there = adj[here][i].first;
            int nextDist = adj[here][i].second + cost;
            
            if (dist[there] > nextDist)
            {
                dist[there] = nextDist;
                pq.push({-nextDist, there});
            }
        }
    }
}

void rev_dijkstra(int start)
{
    priority_queue<pair<int, int>> pq;
    rev_dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        
        if (rev_dist[here] < cost)
            continue;
        
        for (int i = 0; i < rev_adj[here].size(); ++i)
        {
            int there = rev_adj[here][i].first;
            int nextDist = rev_adj[here][i].second + cost;
            
            if (rev_dist[there] > nextDist)
            {
                rev_dist[there] = nextDist;
                pq.push({-nextDist, there});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> x;
    for (int i = 0; i < m; ++i)
    {
        int here, there, cost;
        cin >> here >> there >> cost;
        adj[here].push_back({there, cost});
        rev_adj[there].push_back({here, cost});
    }
    
    for (int i = 1; i <= n; ++i)
    {
        dist[i] = 1e9;
        rev_dist[i] = 1e9;
    }
    
    dijkstra(x);
    rev_dijkstra(x);
    
    int ret = -1;
    for (int i = 1; i <= n; ++i)
    {
        ret = max(ret, dist[i] + rev_dist[i]);
    }
    cout << ret << '\n';
    
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int n, m, k;
int here, there, cost;

const int MAX_V = 10001;
const int MAX_R = 21;

vector<pair<int, int>> adj[MAX_V];
int64 dist[MAX_V][MAX_R];

int64 dijkstra(int src)
{
    memset(dist, 0x3f, sizeof(dist));

    priority_queue<pair<int64, pair<int, int>>> pq;
    dist[src][0] = 0;

    // cost, src, cnt
    pq.push(make_pair(0, make_pair(src, 0)));

    while (!pq.empty())
    {
        int64 cost = -pq.top().first;
        int here = pq.top().second.first;
        int cnt = pq.top().second.second;
        pq.pop();

        if (dist[here][cnt] < cost) continue;

        for (int i = 0; i < (int)adj[here].size(); ++i)
        {
            int there = adj[here][i].first;
            int64 nextDis = cost + adj[here][i].second;

            if (dist[there][cnt] > nextDis)
            {
                dist[there][cnt] = nextDis;
                pq.push(make_pair(-nextDis, make_pair(there, cnt)));
            }

            if (cnt < k && dist[there][cnt + 1] > cost)
            {
                dist[there][cnt + 1] = cost;
                pq.push(make_pair(-cost, make_pair(there, cnt + 1)));
            }
        }
    }

    int64 min_cost = INT64_MAX;
    for (int i = 0; i <= k; ++i)
    {
        min_cost = min(min_cost, dist[n][i]);
    }

    return min_cost;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> k;

    while (m--)
    {
        cin >> here >> there >> cost;
        adj[here].push_back(make_pair(there, cost));
        adj[there].push_back(make_pair(here, cost));
    }
    
    cout << dijkstra(1);

    return 0;
}
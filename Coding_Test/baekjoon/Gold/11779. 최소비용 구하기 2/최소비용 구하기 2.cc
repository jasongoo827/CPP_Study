#include <bits/stdc++.h>

using namespace std;
//using int64 = long long;

const int MAX_V = 1001;
const int INF = 987654321;

int n, m;

vector<pair<int, int>> adj[MAX_V];
int path[MAX_V];
vector<int> path_v;

void dijkstra(int src, int dst)
{
    vector<int> dist(n + 1, INF);
    dist[src] = 0;
    priority_queue<pair<int, int>> pq;

    pq.push(make_pair(0, src));

    while (!pq.empty())
    {
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if (dist[here] < cost) continue;

        for (int i = 0; i < (int)adj[here].size(); ++i)
        {
            int there = adj[here][i].first;
            int nextDist = adj[here][i].second + cost;

            if (dist[there] > nextDist)
            {
                dist[there] = nextDist;
                path[there] = here;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }

    cout << dist[dst] << "\n";
    int temp = dst;
    while (temp)
    {
        path_v.push_back(temp);
        temp = path[temp];
    }
    cout << path_v.size() << "\n";
    for (int i = (int)path_v.size() - 1; i >= 0; i--)
    {
        cout << path_v[i] << " ";
    }
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;

    int here, there, cost;
    while (m--)
    {
        cin >> here >> there >> cost;
        adj[here].push_back(make_pair(there, cost));
    }
    
    int start, end;
    cin >> start >> end;

    dijkstra(start, end);

    return 0;
}
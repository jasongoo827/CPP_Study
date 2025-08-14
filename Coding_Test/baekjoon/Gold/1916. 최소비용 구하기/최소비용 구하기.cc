#include <iostream>
#include <vector>
#include <queue>

#define MAX_V 1001
#define INF 987654321

using namespace  std;

int n, m;

vector<pair<int,int>> adj[MAX_V];

vector<int> dijkstra(int src)
{
    vector<int> dist(n+1, INF);
    dist[src]=0;
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,src));

    while(!pq.empty())
    {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if(dist[here]<cost) continue;

        for(int i=0;i<adj[here].size();++i)
        {
            int there = adj[here][i].first;
            int nextDist = cost+adj[here][i].second;

            if(dist[there]>nextDist)
            {
                dist[there]=nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;

    int here, there, cost;
    for(int i=0;i<m;i++)
    {
        cin>>here>>there>>cost;
        adj[here].push_back(make_pair(there,cost));
    }

    cin>>here>>there;

    vector<int> res = dijkstra(here);

    cout<<res[there];

    return 0;
}

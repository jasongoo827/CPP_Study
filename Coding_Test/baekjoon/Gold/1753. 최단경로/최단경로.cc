#include <iostream>
#include <vector>
#include <queue>

using namespace  std;

const int MAX_V=20005;
const int INF=987654321;

int V,E;
int start;
vector<pair<int,int>> adj[MAX_V];
int dist[MAX_V];

void dijkstra(int src)
{
    dist[src]=0;
    priority_queue<pair<int,int>> pq;

    pq.push(make_pair(0,src));

    while(!pq.empty())
    {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if(dist[here]<cost) continue;

        for(int i=0;i<(int)adj[here].size();++i)
        {
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;

            if(dist[there]>nextDist)
            {
                dist[there]=nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }

    for(int i=1;i<=V;++i)
    {
        if(dist[i]==INF)
            cout<<"INF\n";
        else
            cout<<dist[i]<<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>V>>E>>start;

    int here, there, cost;
    while(E--)
    {
        cin>>here>>there>>cost;
        adj[here].push_back(make_pair(there,cost));
    }

    for(int i=1;i<=V;++i) dist[i]=INF;

    dijkstra(start);

    return 0;
}

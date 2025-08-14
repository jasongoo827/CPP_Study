#include <iostream>
#include <vector>
#include <queue>

using namespace  std;

const int MAX_V=1001;

int V,E,k;
vector<pair<int,int>> adj[MAX_V];
priority_queue<int> res[MAX_V];

void dijkstra(int src)
{
    priority_queue<pair<int,int>> pq;

    res[src].push(0);
    pq.push(make_pair(0,src));

    while(!pq.empty())
    {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        for(int i=0;i<(int)adj[here].size();++i)
        {
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;

            if(res[there].size()<k)
            {
                res[there].push(nextDist);
                pq.push(make_pair(-nextDist, there));
            }
            else if(res[there].top()>nextDist)
            {
                res[there].pop();
                res[there].push(nextDist);
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>V>>E>>k;

    int here, there, cost;
    while(E--)
    {
        cin>>here>>there>>cost;
        adj[here].push_back(make_pair(there,cost));
    }

    dijkstra(1);

    for(int i=1;i<=V;++i)
    {
        if(res[i].size()!=k) cout<<-1<<"\n";
        else cout<<res[i].top()<<"\n";
    }

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int tc;
int n, m, w;
int dist[501];
const int INF = 1e9;
vector<pair<pair<int, int>, int>> edges;

void bellmanFord()
{
    for (int i = 0; i < n; ++i)
    {
        for (int pos = 0; pos < edges.size(); ++pos)
        {
            int here = edges[pos].first.first;
            int there = edges[pos].first.second;
            int cost = edges[pos].second;
            
            if (dist[here] + cost < dist[there])
                dist[there] = dist[here] + cost;
        }
    }
    
    for (int pos = 0; pos < edges.size(); ++pos)
    {
        int here = edges[pos].first.first;
        int there = edges[pos].first.second;
        int cost = edges[pos].second;
        
        if (dist[here] + cost < dist[there])
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> tc;
    while (tc--)
    {
        cin >> n >> m >> w;
        edges.clear();
        for (int i = 0; i < m; ++i)
        {
            int s, e, t;
            cin >> s >> e >> t;
            edges.push_back({{s, e}, t});
            edges.push_back({{e, s}, t});
        }
        for (int i = 0; i < w; ++i)
        {
            int s, e, t;
            cin >> s >> e >> t;
            edges.push_back({{s, e}, -t});
        }
        for (int i = 1; i <= n; ++i)
            dist[i] = INF;
        bellmanFord();
    }
    
    return 0;
}

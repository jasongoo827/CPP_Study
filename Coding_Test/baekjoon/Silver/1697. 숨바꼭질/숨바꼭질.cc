#include <iostream>
#include <queue>

using namespace std;

int n, k;
const int MAX = 100001;
int dist[100001];

int bfs(int start)
{
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    
    while (!q.empty())
    {
        int here = q.front();
        q.pop();
        
        if (here - 1 >= 0 && dist[here - 1] > dist[here] + 1)
        {
            dist[here - 1] = dist[here] + 1;
            q.push(here - 1);
        }
        
        if (here + 1 < MAX && dist[here + 1] > dist[here] + 1)
        {
            dist[here + 1] = dist[here] + 1;
            q.push(here + 1);
        }
        if (here * 2 < MAX && dist[here * 2] > dist[here] + 1)
        {
            dist[here * 2] = dist[here] + 1;
            q.push(here * 2);
        }
    }
    return dist[k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> k;
    
    for (int i = 0; i < MAX; ++i)
        dist[i] = 1e9;
    
    cout << bfs(n) << '\n';
    
    return 0;
}
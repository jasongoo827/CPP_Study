#include <iostream>
#include <queue>

using namespace std;

int n, k;
const int MAX = 100001;
int dist[100001];
int cnt[100001] = {0,};

int bfs(int start)
{
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    cnt[start] = 1;
    
    while (!q.empty())
    {
        int here = q.front();
        q.pop();
        
        if (here - 1 >= 0)
        {
            if (dist[here - 1] > dist[here] + 1)
            {
                dist[here - 1] = dist[here] + 1;
                cnt[here - 1] = cnt[here];
                q.push(here - 1);
            }
            else if (dist[here - 1] == dist[here] + 1)
                cnt[here - 1] += cnt[here];
        }
        
        if (here + 1 < MAX)
        {
            if (dist[here + 1] > dist[here] + 1)
            {
                dist[here + 1] = dist[here] + 1;
                cnt[here + 1] = cnt[here];
                q.push(here + 1);
            }
            else if (dist[here + 1] == dist[here] + 1)
                cnt[here + 1] += cnt[here];
        }
        if (here * 2 < MAX)
        {
            if (dist[here * 2] > dist[here] + 1)
            {
                dist[here * 2] = dist[here] + 1;
                cnt[here * 2] = cnt[here];
                q.push(here * 2);
            }
            else if (dist[here * 2] == dist[here] + 1)
                cnt[here * 2] += cnt[here];
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
    
    cout << bfs(n) << '\n' << cnt[k] << '\n';
    
    return 0;
}
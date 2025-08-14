#include <iostream>
#include <deque>

using namespace std;

int n, k;
const int MAX = 100001;
int dist[100001];

int bfs(int start)
{
    deque<int> dq;
    dist[start] = 0;
    dq.push_back(start);
    
    while (!dq.empty())
    {
        int here = dq.front();
        dq.pop_front();
        
        if (here * 2 < MAX && dist[here * 2] > dist[here])
        {
            dist[here * 2] = dist[here];
            dq.push_front(here * 2);
        }
        if (here + 1 < MAX && dist[here + 1] > dist[here] + 1)
        {
            dist[here + 1] = dist[here] + 1;
            dq.push_back(here + 1);
        }
        if (here - 1 >= 0 && dist[here - 1] > dist[here] + 1)
        {
            dist[here - 1] = dist[here] + 1;
            dq.push_back(here - 1);
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
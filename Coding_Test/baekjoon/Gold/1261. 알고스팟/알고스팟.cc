#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
string s;
int maze[101][101];
int dist[101][101];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int bfs(int y, int x)
{
    deque<pair<int, int>> dq;
    dist[y][x] = 0;
    dq.push_back({y, x});
    
    while (!dq.empty())
    {
        int hereY = dq.front().first;
        int hereX = dq.front().second;
        dq.pop_front();
        
        for (int d = 0; d < 4; ++d)
        {
            int ny = hereY + dy[d];
            int nx = hereX + dx[d];
            
            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            
            int cost = dist[hereY][hereX] + maze[ny][nx];
            
            if (dist[ny][nx] > cost)
            {
                dist[ny][nx] = cost;
                if (maze[ny][nx] == 0)
                    dq.push_front({ny, nx});
                else if (maze[ny][nx] == 1)
                    dq.push_back({ny, nx});
            }            
        }
    }
    return dist[n - 1][m - 1];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;
    
    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        for (int j = 0; j < s.length(); ++j)
        {
            if (s[j] == '0')
                maze[i][j] = 0;
            else if (s[j] == '1')
                maze[i][j] = 1;
        }
    }
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            dist[i][j] = 1e9;
    
    cout << bfs(0, 0) << '\n';
    
    return 0;
}
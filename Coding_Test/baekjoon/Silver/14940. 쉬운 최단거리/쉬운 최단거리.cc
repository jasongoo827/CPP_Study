#include <iostream>
#include <queue>

using namespace std;

int n, m;
int board[1000][1000];
bool visited[1000][1000];
int cnt[1000][1000];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void bfs(int y, int x)
{
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = true;
    
    while (!q.empty())
    {
        int hy = q.front().first;
        int hx = q.front().second;
        
        q.pop();
        
        for (int d = 0; d < 4; ++d)
        {
            int ny = hy + dy[d];
            int nx = hx + dx[d];
            
            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            if (board[ny][nx] == 1 &&!visited[ny][nx])
            {
                visited[ny][nx] = true;
                cnt[ny][nx] = cnt[hy][hx] + 1;
                q.push({ny, nx});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    
    int x, y;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 2)
            {
                y = i;
                x = j;
            }
        }
    
    bfs(y, x);
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (board[i][j] == 1 && cnt[i][j] == 0)
                cout << "-1";
            else
                cout << cnt[i][j];
            cout << " ";
        }
        cout << '\n';
    }
    
    return 0;
}

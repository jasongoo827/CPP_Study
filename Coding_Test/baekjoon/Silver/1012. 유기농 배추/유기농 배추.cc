#include <iostream>

using namespace std;

int t;
int m, n, k;
int board[50][50];
bool visited[50][50];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void dfs(int y, int x)
{
    for (int d = 0; d < 4; ++d)
    {
        int ny = y + dy[d];
        int nx = x + dx[d];
        
        if (ny < 0 || nx < 0 || ny >= m || nx >= n)
            continue;
        
        if (!visited[ny][nx] && board[ny][nx] == 1)
        {
            visited[ny][nx] = true;
            dfs(ny, nx);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> t;
    while (t--)
    {
        cin >> m >> n >> k;
        
        for (int i = 0; i < 50; ++i)
        {
            fill(board[i], board[i] + 50, 0);
            fill(visited[i], visited[i] + 50, false);
        }
        
        while (k--)
        {
            int x, y;
            cin >> x >> y;
            board[x][y] = 1;
        }
        
        int cnt = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!visited[i][j] && board[i][j] == 1)
                {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
    
    return 0;
}

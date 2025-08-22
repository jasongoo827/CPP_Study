#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

int n, l, r;
int board[50][50];
bool visited[50][50];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool bfs(int y, int x)
{
    queue<pair<int, int>> q;
    vector<pair<int, int>> united;
    int sum = board[y][x];
    
    q.push({y, x});
    visited[y][x] = true;
    united.push_back({y, x});
    
    while (!q.empty())
    {
        int hy = q.front().first;
        int hx = q.front().second;   
        q.pop();
        
        for (int d = 0; d < 4; ++d)
        {
            int ny = hy + dy[d];
            int nx = hx + dx[d];
            
            if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx])
                continue;
            int diff = abs(board[hy][hx] - board[ny][nx]);
            if (diff >= l && diff <= r)
            {
                visited[ny][nx] = true;
                q.push({ny, nx});
                united.push_back({ny, nx});
                sum += board[ny][nx];
            }
        }
    }
    
    if (united.size() > 1)
    {
        int avg = sum / united.size();
        for (const auto& [py, px]: united)
            board[py][px] = avg;
        return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> l >> r;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> board[i][j];

    int days = 0;    
    while (true)
    {
        memset(visited, false, sizeof(visited));
        bool moved = false;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!visited[i][j])
                {
                    if (bfs(i, j))
                        moved = true;
                }
            }
        }
        if (!moved)
            break;
        days++;
    }
    cout << days << '\n';
    
    return 0;
}
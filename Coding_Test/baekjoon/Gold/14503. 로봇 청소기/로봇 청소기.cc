#include <iostream>

using namespace std;

int n, m;
int r, c, d;
int room[50][50];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void solve(int y, int x, int d, int& cnt)
{    
    if (room[y][x] == 0)
    {
        room[y][x] = 2;
        cnt++;        
    }
    
    for (int i = 0; i < 4; ++i)
    {
        d = (d + 3) % 4;
        
        int ny = y + dy[d];
        int nx = x + dx[d];
        
        if (ny < 0 || nx < 0 || ny >= n || nx >= m)
            continue;
        if (room[ny][nx] == 0)
        {
            solve(ny, nx, d, cnt);
            return;
        }
    }
    
    int back = (d + 2) % 4;
    int ny = y + dy[back];
    int nx = x + dx[back];
    
    if (ny >= 0 && ny < n && nx >= 0 && nx < m && room[ny][nx] != 1)
        solve(ny, nx, d, cnt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    cin >> r >> c >> d;
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> room[i][j];
    
    int ret = 0;
    solve(r, c, d, ret);
    cout << ret << '\n';
    
    
    return 0;
}
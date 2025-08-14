#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

// boj 16236

int n;
int board[20][20];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int sharkSize = 2;

struct Target
{
    int y, x, dist;
};

Target bfs(int sy, int sx)
{
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<tuple<int, int, int>> q;
    q.push({sy, sx, 0});
    visited[sy][sx] = true;

    Target best = {-1, -1, -1};

    while (!q.empty())
    {
        auto [y, x, d] = q.front();
        q.pop();

        if (best.dist != -1 && d > best.dist)
            continue;

        for (int dir = 0; dir < 4; ++dir) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if (ny < 0 || nx < 0 || ny >= n || nx >= n)
                continue;
            if (visited[ny][nx] || board[ny][nx] > sharkSize)
                continue;

            visited[ny][nx] = true;

            if (board[ny][nx] > 0 && board[ny][nx] < sharkSize)
            {
                if (best.dist == -1 || d + 1 < best.dist ||
                    (d + 1 == best.dist && (ny < best.y || (ny == best.y && nx < best.x))))
                {
                    best = {ny, nx, d + 1};
                }
            }

            q.push({ny, nx, d + 1});
        }
    }

    return best;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int startX, startY;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 9)
            {
                startY = i;
                startX = j;
                board[i][j] = 0;
            }
        }
    }

    int time = 0;
    int eatCount = 0;
    while (true)
    {
        Target target = bfs(startY, startX);
        
        if (target.dist == -1)
            break;
        startY = target.y;
        startX = target.x;

        time += target.dist;
        eatCount++;
        board[startY][startX] = 0;

        if (eatCount == sharkSize)
        {
            sharkSize++;
            eatCount = 0;
        }
    }
    cout << time << '\n';

   return 0;
}
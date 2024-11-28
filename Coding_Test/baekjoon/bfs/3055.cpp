#include <iostream>
#include <queue>
#define MAX 51

using namespace std;

int r, c;
int dstY, dstX;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
char map[MAX][MAX];
int visited[MAX][MAX];

void bfs(queue<pair<int, int>> &q)
{
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if (y == dstY && x == dstX)
        {
            cout << visited[y][x] << '\n';
            return;
        }

        for (int d = 0; d < 4; ++d)
        {
            int ny = y + dy[d], nx = x + dx[d];
            if (ny < 1 || ny > r || nx < 1 || nx > c)
                continue;
            if (map[y][x] == 'S' && (map[ny][nx] == '.' || map[ny][nx] == 'D'))
            {
                map[ny][nx] = 'S';
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx});
            }
            else if (map[y][x] == '*' && (map[ny][nx] == '.' || map[ny][nx] == 'S'))
            {
                map[ny][nx] = '*';
                q.push({ny, nx});
            }
        }
    }
    cout << "KAKTUS\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c;

    queue<pair<int, int>> q;
    for (int i = 1; i <= r; ++i)
    {
        for (int j = 1; j <= c; ++j)
        {
            cin >> map[i][j];
            if (map[i][j] == 'D')
                dstY = i, dstX = j;
            else if (map[i][j] == 'S')
                q.push({i, j});
        }
    }
    for (int i = 1; i <= r; ++i)
    {
        for (int j = 1; j <= c; ++j)
        {
            if (map[i][j] == '*')
                q.push({i, j});
        }
    }
    bfs(q);
}

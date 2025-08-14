#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 1001

using namespace std;

int n, m;
int map[MAX][MAX];
// 벽 부수는 여부에 따른 방문 배열 + cnt 배열
// 메모리 관점에서 시간복잡도를 생각하자.
int visited[2][MAX][MAX];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void bfs()
{
    // 한번에 관리하는 것보다 나눠 하는 게 좀 더 효율적이다.
    queue<pair<int, int>> q;
    queue<int> skipq;
    q.push({1, 1});
    skipq.push(0);
    visited[0][1][1] = 1;

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        int broken = skipq.front();
        q.pop();
        skipq.pop();

        if (y == n && x == m)
        {
            cout << visited[broken][y][x] << '\n';
            return;
        }

        for (int d = 0; d < 4; ++d)
        {
            int ny = y + dy[d];
            int nx = x + dx[d];

            if (ny < 1 || ny > n || nx < 1 || nx > m)
                continue;
            if (map[ny][nx] == 0 && visited[broken][ny][nx] == 0)
            {
                visited[broken][ny][nx] = visited[broken][y][x] + 1;
                q.push({ny, nx});
                skipq.push(broken);
            }
            if (map[ny][nx] == 1 && broken == 0 && visited[1][ny][nx] == 0)
            {
                visited[1][ny][nx] = visited[broken][y][x] + 1;
                q.push({ny, nx});
                skipq.push(1);
            }
        }
    }
    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            char c;
            cin >> c;
            map[i][j] = c - '0';
        }
    }

    bfs();
    return 0;
}

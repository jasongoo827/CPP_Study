#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX 9

using namespace std;

int n, m;
int map[MAX][MAX];
int comb[3];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int ret = 0;

void bfs()
{
    // 바로 map을 바꾸는 것은 안된다.
    int tmpMap[MAX][MAX];
    memcpy(tmpMap, map, sizeof(tmpMap));

    // indexing 하는 방법 바로 떠올리기
    for (int i = 0; i < 3; ++i)
    {
        int x = (comb[i] - 1) % m + 1;
        int y = (comb[i] - 1) / m + 1;
        if (map[y][x] != 0)
            return;
        tmpMap[y][x] = 1;
    }

    queue<pair<int, int>> q;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (tmpMap[i][j] == 2)
                q.push({i, j});

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int d = 0; d < 4; ++d)
        {
            int ny = y + dy[d], nx = x + dx[d];
            if (ny < 1 || ny > n || nx < 1 || nx > m)
                continue;
            if (tmpMap[ny][nx] == 0)
            {
                tmpMap[ny][nx] = 2;
                q.push({ny, nx});
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (tmpMap[i][j] == 0)
                cnt++;
    ret = max(ret, cnt);
}

// 조합 짜기
void combination(int depth, int next)
{
    if (depth == 3)
    {
        bfs();
        return;
    }
    for (int i = next; i <= n * m; ++i)
    {
        comb[depth] = i;
        combination(depth + 1, i + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> map[i][j];
    combination(0, 1);
    cout << ret << '\n';
}
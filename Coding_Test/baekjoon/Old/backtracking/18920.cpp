#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// boj 18920

int board[10][10];
bool visited[10][10];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int n, m, k;
int ret = INT_MIN;

bool isAdj(int y, int x)
{
    for (int d = 0; d < 4; ++d)
    {
        int ny = dy[d] + y;
        int nx = dx[d] + x;

        if (ny < 0 || nx < 0 || ny >= n || nx >= m)
            continue;
        if (visited[ny][nx])
            return true;
    }
    return false;
}

void dfs(int picked, int sum, int y, int x)
{
    if (picked == k)
    {
        ret = max(ret, sum);
        return;
    }

    visited[y][x] = true;
    int start = y * m + x + 1;
    for (int i = start; i < n * m; ++i)
    {
        int ni = i / m;
        int nj = i % m;

        if (!isAdj(ni, nj))
            dfs(picked + 1, sum + board[ni][nj], ni, nj);
    }
    visited[y][x] = false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> board[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            dfs(1, board[i][j], i, j);
    cout << ret << '\n';

    return 0;
}
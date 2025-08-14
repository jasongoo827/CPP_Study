#include <iostream>
#include <vector>
#include <queue>
#define MAX 101

using namespace std;

int n, m;

int arr[MAX][MAX];
queue<pair<int,int> > q;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfsMelt(int y, int x)
{
    int cnt = 0;

    for (int d = 0; d < 4; ++d)
    {
        int ny = y + dy[d], nx = x + dx[d];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n)
            continue;
        if (arr[ny][nx] == -1)
            cnt++;
    }
    if (cnt >= 2)
        q.push({y, x});
}

void melt()
{
    for (int i = 1; i < n - 1; ++i)
    {
        for (int j = 1; j < m - 1; ++j)
        {
            if (arr[i][j] == 1)
                dfsMelt(i, j);
        }
    }
}

void dfs(int y, int x)
{
    if (arr[y][x] != 0)
        return;
    arr[y][x] = -1;

    for (int d = 0; d < 4; ++d)
    {
        int ny = y + dy[d], nx = x + dx[d];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n)
            continue;
        if (arr[ny][nx] == 0)
            dfs(ny, nx);
    }
}

int solve()
{
    int ret = 0;
    dfs(0, 0);

    while (1)
    {
        melt();
        if (q.empty())
            break;
        while (!q.empty())
        {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            arr[y][x] = -1;
            for (int d = 0; d < 4; ++d)
            {
                int ny = y + dy[d], nx = x + dx[d];
                if (arr[ny][nx] == 0)
                    dfs(ny, nx);
            }
        }
        ret++;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> arr[i][j];

    cout << solve() << '\n';
}
#include <bits/stdc++.h>

using namespace std;

int m, n;

int arr[501][501];
int cache[501][501];

// 상 하 좌 우
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int solve(int y, int x)
{
    if (y == m - 1 && x == n - 1) return 1;

    int& ret = cache[y][x];
    if (ret != -1) return ret;

    ret = 0;
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

        if (arr[ny][nx] < arr[y][x])
            ret += solve(ny, nx);
    }

    return ret;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> m >> n;

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> arr[i][j];

    memset(cache, -1, sizeof(cache));

    cout << solve(0, 0);

    return 0;
}
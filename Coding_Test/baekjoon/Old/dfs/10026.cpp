#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 101

int n;
char arr[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int y, int x, char color)
{
    visited[y][x] = true;

    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;        
        if (!visited[ny][nx] && arr[ny][nx] == color)
            dfs(ny, nx, color);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> arr[i][j];

    int normal = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (!visited[i][j])
            {
                dfs(i, j, arr[i][j]);
                normal++;
            }
        }
    }

    for (int i = 0; i < n; ++i)
        fill_n(visited[i], n, 0);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (arr[i][j] == 'R')
                arr[i][j] = 'G';
        }
    }

    int blind = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (!visited[i][j])
            {
                dfs(i, j, arr[i][j]);
                blind++;
            }
        }
    }

    cout << normal << " " << blind << '\n';
}
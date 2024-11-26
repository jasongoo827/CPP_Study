#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 1001

using namespace std;

int m, n;
int box[MAX][MAX];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

struct Data
{
    int y;
    int x;
    int days;
};

int bfs()
{
    queue<Data> q;
    int ret = 0;
    int cnt = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (box[i][j] == 1)
                q.push({i, j, 0});
            else if (box[i][j] == 0)
                cnt++;
        }
    }

    while (!q.empty())
    {
        int y = q.front().y;
        int x = q.front().x;
        int days = q.front().days;
        ret = max(ret, days);
        q.pop();

        for (int d = 0; d < 4; ++d)
        {
            int ny = y + dy[d], nx = x + dx[d];
            
            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (box[ny][nx] == 0)
            {
                q.push({ny, nx, days + 1});
                box[ny][nx] = 1;
                cnt--;
            }
        }
    }

    if (cnt == 0)
        return ret;
    else
        return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> box[i][j];
    
    cout << bfs() << '\n';
}
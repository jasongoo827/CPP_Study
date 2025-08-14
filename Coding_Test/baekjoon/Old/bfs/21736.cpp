#include <iostream>
#include <queue>

using namespace std;

// boj 21736

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int n, m;
char arr[600][600];
bool visited[600][600];
int ret = 0;

void bfs(int y, int x)
{
    queue<pair<int, int>> q;

    q.push({y, x});
    visited[y][x] = true;

    while (!q.empty())
    {
        auto here = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int ny = here.first + dy[i];
            int nx = here.second + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue; 
            if (arr[ny][nx] != 'X' && !visited[ny][nx])
            {
                if (arr[ny][nx] == 'P')
                    ret++;
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    int y, x;

    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); ++j)
        {
            arr[i][j] = s[j];

            if (arr[i][j] == 'I')
            {
                y = i;
                x = j;
            }
        }
    }

    bfs(y, x);
    if (ret == 0)
        cout << "TT\n";
    else
        cout << ret << '\n';

    return 0;
}
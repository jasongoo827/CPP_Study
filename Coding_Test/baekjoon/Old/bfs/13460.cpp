#include <iostream>
#include <queue>
#include <cmath>

using namespace std;
using pii = pair<int, int>;

// boj 13460

char board[10][10];
bool visited[10][10][10][10];

int n, m;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

struct State
{
    pii red, blue;
    int moves;
};

pii move_ball(pii pos, int dir)
{
    int y = pos.first;
    int x = pos.second;
    
    while (true)
    {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        
        if (board[ny][nx] == '#')
            break;
        if (board[ny][nx] == 'O')
            return {ny, nx};
        
        y = ny;
        x = nx;
    }
    
    return {y, x};
}

int bfs(pii& red_start, pii& blue_start)
{
    queue<State> q;
    q.push({red_start, blue_start, 0});
    visited[red_start.first][red_start.second][blue_start.first][blue_start.second] = true;
    
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        if (cur.moves >= 10)
            continue;

        for (int d = 0; d < 4; ++d)
        {
            pii new_red = move_ball(cur.red, d);
            pii new_blue = move_ball(cur.blue, d);
            
            if (board[new_blue.first][new_blue.second] == 'O')
                continue;
            if (board[new_red.first][new_red.second] == 'O')
                return cur.moves + 1;
            if (new_red == new_blue)
            {
                int red_dist = abs(new_red.first - cur.red.first) + abs(new_red.second - cur.red.second);
                int blue_dist = abs(new_blue.first - cur.blue.first) + abs(new_blue.second - cur.blue.second);

                if (red_dist > blue_dist)
                {
                    new_red.first -= dy[d];
                    new_red.second -= dx[d];
                }
                else
                {
                    new_blue.first -= dy[d];
                    new_blue.second -= dx[d];
                }
            }

            if (visited[new_red.first][new_red.second][new_blue.first][new_blue.second])
                continue;
            
            visited[new_red.first][new_red.second][new_blue.first][new_blue.second] = true;
            q.push({new_red, new_blue, cur.moves + 1});
        }       
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    pair<pii, pii> start;
    pii red_start, blue_start;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0 ; j < m; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 'R')
            {
                red_start.first = i;
                red_start.second = j;
                board[i][j] = '.';
            }
            else if (board[i][j] == 'B')
            {
                blue_start.first = i;
                blue_start.second = j;
                board[i][j] = '.';
            }
        }
    }

   cout << bfs(red_start, blue_start) << '\n';

    return 0;
}
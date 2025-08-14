#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#define MAX 101
#define endl '\n'

using namespace std;

int n, k, l;
int board[MAX][MAX];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
vector<pair<int,char>> info;

void input()
{
    cin >> n >> k;
    memset(board, 0, sizeof(board));
    while (k--)
    {
        int y, x;
        cin >> y >> x;
        board[y - 1][x - 1] = 1;
    }
    cin >> l;
    while (l--)
    {
        int x;
        char c;
        cin >> x >> c;
        info.push_back(make_pair(x, c));
    }
}

int turn_dir(int cur_dir, char next_dir)
{
    if (cur_dir == 0)
    {
        if (next_dir == 'L') return (3);
        else if (next_dir == 'D') return (1);
    }
    else if (cur_dir == 1)
    {
        if (next_dir == 'L') return (0);
        else if (next_dir == 'D') return (2);
    }
    else if (cur_dir == 2)
    {
        if (next_dir == 'L') return (1);
        else if (next_dir == 'D') return (3);
    }
    else if (cur_dir == 3)
    {
        if (next_dir == 'L') return (2);
        else if (next_dir == 'D') return (0);
    }
}

void solve()
{
    deque<pair<int,int>> Q;
    int time = 0;
    int y = 0;
    int x = 0;
    int d = 0;
    int idx = 0;

    Q.push_back(make_pair(y,x));
    board[y][x] = 2;
    while (1)
    {
        time++;

        int ny = y + dy[d];
        int nx = x + dx[d];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n || board[ny][nx] == 2)
            break;
        else if (board[ny][nx] == 0)
        {
            board[ny][nx] = 2;
            board[Q.back().first][Q.back().second] = 0;
            Q.push_front(make_pair(ny, nx));
            Q.pop_back();
        }
        else if (board[ny][nx] == 1)
        {
            board[ny][nx] = 2;
            Q.push_front(make_pair(ny, nx));
        }

        if (idx < (int)info.size())
        {
            if (time == info[idx].first)
            {
                if (info[idx].second == 'L')
                    d = turn_dir(d, 'L');
                else if (info[idx].second == 'D')
                    d = turn_dir(d, 'D');
                idx++;
            }
        }
        x = nx;
        y = ny;
    }
    cout << time << endl;
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solve();
}
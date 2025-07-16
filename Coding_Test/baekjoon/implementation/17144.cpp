#include <iostream>

using namespace std;

// boj 17144

int r, c, t;
int board[50][50];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

struct Point
{
    int y, x;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c >> t;

    Point up, down;
    bool flag = true;
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++ j)
        {
            cin >> board[i][j];
            if (board[i][j] == -1 && flag)
            {
                up.y = i;
                up.x = j;
                down.y = i + 1;
                down.x = j;
                flag = false;
            }
        }
    }

    int ret = 0;
    while (t--)
    {
        int tmp[50][50];
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                tmp[i][j] = board[i][j];
        
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (tmp[i][j] > 0)
                {
                    int amount = tmp[i][j] / 5;
                    for (int dir = 0; dir < 4; ++dir)
                    {
                        int ny = i + dy[dir];
                        int nx = j + dx[dir];

                        if (ny >= r || nx >= c || ny < 0 || nx < 0)
                            continue;
                        if ((ny == up.y && nx == up.x) || (ny == down.y && nx == down.x))
                            continue;

                        board[ny][nx] += amount;
                        board[i][j] -= amount;
                    }
                }
            }
        }

        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                tmp[i][j] = board[i][j];
        
        board[up.y][up.x + 1] = 0;
        for (int i = up.x + 1; i < c - 1; ++i)
            board[up.y][i + 1] = tmp[up.y][i];
        for (int i = up.y; i >= 1; --i)
            board[i - 1][c - 1] = tmp[i][c - 1];
        for (int i = c - 1; i >= 1; --i)
            board[0][i - 1] = tmp[0][i];
        for (int i = 0; i < up.y - 1; ++i)
            board[i + 1][0] = tmp[i][0];

        board[down.y][down.x + 1] = 0;
        for (int i = down.x + 1; i < c - 1; ++i)
            board[down.y][i + 1] = tmp[down.y][i];
        for (int i = down.y; i < r - 1; ++i)
            board[i + 1][c - 1] = tmp[i][c - 1];
        for (int i = c - 1; i >= 1; --i)
            board[r - 1][i - 1] = tmp[r - 1][i];
        for (int i = r - 1; i >= down.y + 2; --i)
            board[i - 1][0] = tmp[i][0];
    }   

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            if (board[i][j] > 0)
                ret += board[i][j];
        }
    }
    cout << ret << '\n';

    return 0;
}
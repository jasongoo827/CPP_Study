#include <iostream>

using namespace std;

// boj 2448

int n;
char board[3072][6143];

void record_star(int y, int x)
{
    board[y][x] = '*';
    board[y + 1][x - 1] = '*';
    board[y + 1][x + 1] = '*';
    for (int i = -2; i <= 2; ++i)
        board[y + 2][x + i] = '*';
}

void recursive_star(int n, int y, int x)
{
    if (n == 3)
    {
        record_star(y, x);
        return;
    }

    recursive_star(n / 2, y, x);
    recursive_star(n / 2, y + n / 2, x - n / 2);
    recursive_star(n / 2, y + n / 2, x + n / 2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < 3072; ++i)
    {
        for (int j = 0; j < 6143; ++j)
            board[i][j] = ' ';
    }

    recursive_star(n, 0, (2 * n - 1) / 2);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 2 * n - 1; ++j)
            cout << board[i][j];
        cout << '\n';
    }

    return 0;
}
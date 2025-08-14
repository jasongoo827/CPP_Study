#include <bits/stdc++.h>

using namespace std;

int board[5][5];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
set<int> numset;

void dfs(int toPick, int y, int x, int sum) {
    if (toPick == 0) {
        numset.insert(sum);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (0 <= nx && nx < 5 && 0 <= ny && ny < 5) {
            dfs(toPick - 1, ny, nx, sum * 10 + board[ny][nx]);
        }
    }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            cin >> board[i][j];
        }
    }
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            dfs(5, i, j, board[i][j]);
        }
    }

    cout <<numset.size();

	return 0;
}
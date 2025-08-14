#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

#define MAX 301

int n, m;
int arr[MAX][MAX];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool visited[MAX][MAX];

void melt()
{
	int tmp[MAX][MAX] = { 0 };

	for (int i = 1; i < n - 1; ++i)
	{
		for (int j = 1; j < m - 1; ++j)
		{
			if (arr[i][j] > 0)
			{
				int cnt = 0;
				for (int dir = 0; dir < 4; ++dir)
				{
					int ny = i + dy[dir], nx = j + dx[dir];
					if (arr[ny][nx] == 0)
						cnt++;
				}
				tmp[i][j] = max(0, arr[i][j] - cnt);
			}
		}
	}
	for (int i = 1; i < n - 1; ++i)
		for (int j = 1; j < m - 1; ++j)
			arr[i][j] = tmp[i][j];
}

void dfs(int y, int x)
{
	visited[y][x] = true;

	for (int dir = 0; dir < 4; ++dir)
	{
		int ny = y + dy[dir], nx = x + dx[dir];
		if (!visited[ny][nx] && arr[ny][nx] > 0)
		{
			dfs(ny, nx);
		}
	}
}

bool chk()
{
	for (int i = 1; i < n - 1; ++i)
	{
		for (int j = 1; j < m - 1; ++j)
		{
			if (arr[i][j] > 0)
				return false;
		}
	}
	return true;
}

int solve()
{
	int ret = 0;

	while (1)
	{
		melt();
		ret++;
		memset(visited, false, sizeof(visited));
		if (chk()) return 0;

		int cnt = 0;
		for (int i = 1; i < n - 1; ++i)
		{
			for (int j = 1; j < m - 1; ++j)
			{
				if (!visited[i][j] && arr[i][j] > 0)
				{
					dfs(i, j);
					cnt++;
				}
			}
		}
		if (cnt >= 2)
			break;
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
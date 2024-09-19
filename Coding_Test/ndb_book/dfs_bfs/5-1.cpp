#include <iostream>
#include <vector>

using namespace std;

int graph[1000][1000];
bool visited[1000][1000];
int n, m;
string line;
int ret = 0;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

// visited 배열이 꼭 필요한가?
// dfs를 bool로 반환하는 것도 가능하다.
// 모든 방향을 재귀적으로 호출하는 것이 더 좋을까?

void dfs(int y, int x)
{
	visited[x][y] = true;

	for (int d = 0; d < 4; ++d)
	{
		int ny = y + dy[d], nx = x + dx[d];
		if (ny < 0 || nx < 0 || ny >= m || nx >= n)
			continue;
		if (!visited[nx][ny] && graph[nx][ny] == 0)
			dfs(ny, nx);
	}
}

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> line;
		for (int j = 0; j < m; ++j)
			graph[i][j] = line[j] - '0';
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (!visited[i][j] && graph[i][j] == 0)
			{
				dfs(j, i);
				ret++;
			}
		}
	}
	cout << ret << endl;
}
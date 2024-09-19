#include <iostream>
#include <queue>

using namespace std;

int n, m;
string line;
// 언제 1을 더 키운 크기로 배열을 잡는 것이 좋을까
int graph[201][201];
int ret = 0;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

void bfs(int x, int y)
{
	queue<pair<int,int> > q;
	q.push(make_pair(x, y));

	while (!q.empty())
	{
		pair<int, int> p = q.front();
		q.pop();

		for (int d = 0; d < 4; ++d)
		{
			int nx = p.first + dx[d], ny = p.second + dy[d];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (graph[nx][ny] == 0)
				continue;
			if (graph[nx][ny] == 1)
			{
				q.push(make_pair(nx, ny));
				graph[nx][ny] = graph[x][y] + 1;
			}
		}
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
	bfs(0, 0);
	cout << graph[n - 1][m - 1] << endl;
}
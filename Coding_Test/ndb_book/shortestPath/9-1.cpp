#include <iostream>
#include <queue>
#include <vector>
#include <utility>

#define INF 1e9

using namespace std;

int n, m, x, k;
int graph[101][101];

int main(void)
{
	cin >> n >> m;

	for (int i = 0; i < 101; ++i)
		fill(graph[i], graph[i] + 101, INF);

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		graph[a][b] = graph[b][a] = 1;
	}
	cin >> x >> k;

	for (int i = 1; i <= n; ++i)
		graph[i][i] = 0;

	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
	
	if (graph[1][k] == INF || graph[k][x] == INF)
		cout << "-1\n";
	else
		cout << graph[1][k] + graph[k][x] << '\n';
}
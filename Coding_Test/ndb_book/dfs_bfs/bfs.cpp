#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool visited[9];
vector<int> graph[9];

void bfs(int start)
{
	queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		cout << x << ' ';
		for (int i = 0; i < graph[x].size(); ++i)
		{
			int y = graph[x][i];
			if (!visited[y])
			{
				q.push(y);
				visited[y] = true;
			}
		}
	}
}

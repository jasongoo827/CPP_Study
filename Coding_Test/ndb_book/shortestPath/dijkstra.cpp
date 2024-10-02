#include <iostream>
#include <vector>
#include <utility>
#include <queue>

#define INF 1e9

using namespace std;

int n, m, start;
vector<pair<int, int> > graph[100001];
ind d[100001];

void dijkstra(int start)
{
	priority_queue<pair<int, int> > pq;

	pq.push({0, start});
	d[start] = 0;
	while (!pq.empty())
	{
		int dist = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (d[here] < dist) continue;
		for (size_t i = 0; i < graph[here].size(); ++i)
		{
			int there = graph[here][i].first;
			int cost = dist + graph[here][i].second;
			if (cost < d[there])
			{
				d[there] = cost;
				pq.push(make_pair(-cost, there));
			}
		}
	}
}

int main(void)
{
	cin >> n >> m >> start;
	
	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
	}

	fill_n(d, d + 100001, INF);

	dijkstra(start);
	for (int i = 1; i <= n; ++i)
	{
		if (d[i] == INF)
			cout << "INFINITY\n";
		else
			cout << d[i] << '\n';
	}
}
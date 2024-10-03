#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define MAX_N 30001
#define INF 1e9

using namespace std;

int n, m, c;
vector<pair<int, int> > graph[MAX_N];
int d[MAX_N];

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
			int cost = graph[here][i].second + dist;
			if (cost < d[there])
			{
				d[there] = cost;
				pq.push({-cost, there});
			}
		}
	}
}

int main(void)
{
	cin >> n >> m >> c;

	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
	}
	fill_n(d, d + MAX_N, INF);
	dijkstra(c);

	int cnt = 0;
	int ret = -1;
	for (int i = 0; i < n; ++i)
	{
		if (d[i] != INF)
		{
			cnt++;
			ret = max(ret, d[i]);
		}
	}
	cout << cnt - 1<< " " << ret << '\n';
}
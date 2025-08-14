#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#define MAX 10001

using namespace std;

int v, e;
int id = 1;
int p[MAX];
bool finished[MAX];
vector<int> graph[MAX];
stack<int> s;
vector<vector<int>> SCC;

int findSCC_DFS(int here)
{
	p[here] = id++;
	s.push(here);

	int parent = p[here];
	for (size_t i = 0; i < graph[here].size(); ++i)
	{
		int there = graph[here][i];
		if (p[there] == 0)
			parent = min(parent, findSCC_DFS(there));
		else if (!finished[there])
			parent = min(parent, p[there]);
	}

	if (parent == p[here])
	{
		vector<int> scc;
		while (true)
		{
			int there = s.top();
			s.pop();
			scc.push_back(there);
			finished[there] = true;
			if (here == there)
				break;
		}
		sort(scc.begin(), scc.end());
		SCC.push_back(scc);
	}
	return parent;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> v >> e;

	for (int i = 0; i < e; ++i)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}

	fill_n(p, v + 1, 0);
	fill_n(finished, v + 1, false);

	for (int i = 1; i <= v; ++i)
	{
		if (p[i] == 0)
			findSCC_DFS(i);
	}

	sort(SCC.begin(), SCC.end());
	cout << SCC.size() << '\n';
	for (auto& scc : SCC)
	{
		for (auto& v : scc)
			cout << v << " ";
		cout << "-1\n";
	}
	
	return 0;
}

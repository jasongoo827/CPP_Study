#include <iostream>

using namespace std;

int v, e;
int parent[100001];

int findParent(int x)
{
	// 경로 압축 기법
	// find 함수를 재귀적으로 호출해, 부모 테이블값을 갱신.
	if (parent[x] == x)
		return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b)
{
	a = findParent(a);
	b = findParent(b);

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int main(void)
{
	cin >> v >> e;

	for (int i = 1; i <= v; ++i)
		parent[i] = i;
	
	for (int i = 0; i < e; ++i)
	{
		int a, b;
		cin >> a >> b;
		unionParent(a, b);
	}

	cout << "각 원소가 속한 집합: ";
	for (int i = 1; i <= v; ++i)
		cout << findParent(i) << ' ';
	cout << '\n';

	cout << "부모 테이블: ";
	for (int i = 1; i <= v; ++i)
		cout << parent[i] << ' ';
	cout << '\n';
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, x;
	string cmd;
	queue<int> q;

	scanf("%d", &n);

	while (n--) {
		cin >> cmd;

		if (cmd == "push") {
			scanf("%d", &x);
			q.push(x);
		}
		else if (cmd == "front") {
			if (!q.size()) {
				printf("-1\n");
			}
			else {
				printf("%d\n", q.front());
			}
		}
		else if (cmd == "back") {
			if (!q.size()) {
				printf("-1\n");
			}
			else {
				printf("%d\n", q.back());
			}
		}
		else if (cmd == "size") {
			printf("%d\n", q.size());
		}
		else if (cmd == "empty") {
			if (!q.size()) printf("1\n");
			else printf("0\n");
		}
		else if (cmd == "pop") {
			if (!q.size()) printf("-1\n");
			else {
				printf("%d\n", q.front());
				q.pop();
			}
		}

	}

}
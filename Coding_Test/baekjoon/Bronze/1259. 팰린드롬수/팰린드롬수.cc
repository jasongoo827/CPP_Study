#include <bits/stdc++.h>

using namespace std;

int main()
{
	string str;

	while (1) {
		cin >> str;
		if (str == "0") break;

		bool flag = true;

		for (int i = 0; i < str.size() / 2; i++) {
			if (str[i] != str[str.size() - 1 - i]) {
				printf("no\n");
				flag = false;
				break;
			}
		}

		if (flag) printf("yes\n");

	}
}
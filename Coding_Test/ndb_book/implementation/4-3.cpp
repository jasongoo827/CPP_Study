#include <iostream>

using namespace std;

string pos;
int row, col;
int ret = 0;

int dy[8] = {1, 2, -1, -2, -1, -2, 1, 2};
int dx[8] = {-2, -1, -2, -1, 2, 1, 2, 1};

int main(void)
{
	cin >> pos;

	row = pos[1] - '1';
	col = pos[0] - 'a';

	for (int i = 0; i < 8; ++i)
	{
		int nx = row + dx[i], ny = col + dy[i];
		if (nx < 0 || ny < 0 || nx > 7 || ny > 7)
			continue ;
		ret++;
	}
	cout << ret << endl;
}
#include <iostream>

using namespace std;

int n, m;
int x, y, d;

// 0으로 초기화
int map[50][50] = {0,};

// 북, 동, 남, 서
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int ret = 0;

int main(void)
{
	cin >> n >> m;
	cin >> x >> y >> d;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			cin >> map[i][j];
	}

	while (true)
	{
		// 네 방향 이미 가본 칸 or 바다로 되어 있는 칸
		int nd, nx, ny;
		// 모든 방향이 막혀있는 곳을 turn_time으로 표현 가능.
		if (map[x - 1][y] == 1 || map[x - 1][y] == 2 || map[x][y - 1] == 1 || map[x][y - 1] == 2 || \
		map[x + 1][y] == 1 || map[x + 1][y] == 2 || map[x][y + 1] == 1 || map[x][y + 1] == 2)
		{
			nd = (d + 2) % 4;
			nx = x + dx[nd], ny = y + dy[nd];
			// 뒤쪽 방향이 바다인 칸이면 멈춤.
			if (map[nx][ny] == 1)
				break ;
			x = nx, y = ny;
			ret++;
			continue ;
		}
		nd = (d == 0)? 3: d - 1;
		nx = x + dx[nd], ny = y + dy[nd];
		// 왼쪽 방향에 아직 가보지 않은 칸이 존재한다면, 왼쪽 방향으로 회전한 다음 한 칸 전진.
		if (map[nx][ny] == 0)
		{
			d = nd;
			map[x][y] = 2;
			x = nx, y = ny;
			// ret++; 뒤로 가는 것은 방문했던 칸으로 가는 것이기 때문에 방문 포함 X.
		}
		else
			d = nd;
	}
	cout << ret << endl;

}
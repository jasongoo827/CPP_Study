#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int n;
string cmd;
vector<char> v;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool checkMap(int x, int y)
{
	if (x < 1 || x > n || y < 1 || y > n)
		return false;
	return true;
}

void addDir(int& nx, int& ny, int& x, int& y, int i)
{
	nx = x + dx[i];
	ny = y + dy[i];
}

int main()
{
	int x = 1, y = 1;

	cin >> n >> cmd;

	// 공백 기준 파싱
	// 공백이 아닌 구분자는 getline함수에 delimeter를 사용한다.
	istringstream iss(cmd);
	char c;
	while (iss >> c)
		v.push_back(c);
	
	// 좌표를 최대한 덜 계산하는 방법을 찾아보자.
	for (size_t i = 0; i < v.size(); ++i)
	{
		int nx = 0, ny = 0;
		if (v[i] == 'L')
			addDir(nx, ny, x, y, 0);
		else if (v[i] == 'R')
			addDir(nx, ny, x, y, 1);
		else if (v[i] == 'U')
			addDir(nx, ny, x, y, 2);
		else if (v[i] == 'D')
			addDir(nx, ny, x, y, 3);
		if (!checkMap(nx, ny))
			continue ;
		x = nx, y = ny;
	}
	
	cout << x << " " << y << endl;
}
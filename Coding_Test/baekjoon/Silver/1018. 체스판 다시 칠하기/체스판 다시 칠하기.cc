#include <bits/stdc++.h>

using namespace std;

int INF = 987654321;
int n, m;

const char bFirstBoard[9][9] = {{"BWBWBWBW"},{"WBWBWBWB"}, {"BWBWBWBW"},{"WBWBWBWB"},
{"BWBWBWBW"},{"WBWBWBWB"}, {"BWBWBWBW"},{"WBWBWBWB"}};

const char wFirstBoard[9][9]= { {"WBWBWBWB"} ,{"BWBWBWBW"},{"WBWBWBWB"}, {"BWBWBWBW"},{"WBWBWBWB"},
{"BWBWBWBW"},{"WBWBWBWB"}, {"BWBWBWBW"}};

char board[51][51];;

int bFirstCompare(int y, int x)
{
	int rePainted = 0;
	for (int i = y; i < y + 8; i++) {
		for (int j = x; j < x + 8; j++) {
			if (board[i][j]!= bFirstBoard[i-y][j-x]) rePainted++;
		}
	}
	return rePainted;
}

int wFirstCompare(int y, int x)
{
	int rePainted = 0;
	for (int i = y; i < y + 8; i++) {
		for (int j = x; j < x + 8; j++) {
			if (board[i][j] != wFirstBoard[i - y][j - x]) rePainted++;
		}
	}
	return rePainted;
}

int main() 
{
	scanf("%d %d", &n, &m);
			
	for (int i = 0; i < n; i++) {
		scanf("%s", board[i]);
	}

	int res = INF;

	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			res = min(res, min(bFirstCompare(i,j), wFirstCompare(i,j)));
		}
	}
	printf("%d\n", res);
}
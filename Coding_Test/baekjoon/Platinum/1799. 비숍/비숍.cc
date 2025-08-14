#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int board[10][10];
bool d1[20], d2[20];

void dfs(int idx, int cnt, int& maxCnt, vector<pair<int, int>>& cells)
{
    if (idx == cells.size())
    {
        maxCnt = max(maxCnt, cnt);
        return;
    }
    
    int y = cells[idx].first;
    int x = cells[idx].second;
    
    if (!d1[y + x] && !d2[y - x + n - 1])
    {
        d1[y + x] = d2[y - x + n - 1] = true;
        dfs(idx + 1, cnt + 1, maxCnt, cells);
        d1[y + x] = d2[y - x + n - 1] = false;
    }
    dfs(idx + 1, cnt, maxCnt, cells);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<pair<int, int>> black;
    vector<pair<int, int>> white;
    
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
            {
                if ((i + j) % 2 == 0)
                    black.push_back({i, j});
                else
                    white.push_back({i, j});
            }
        }
    }
    
    int blackCnt, whiteCnt = -1;
    
    dfs(0, 0, blackCnt, black);
    fill_n(d1, 20, false);
    fill_n(d2, 20, false);
    dfs(0, 0, whiteCnt, white);
    
    cout << blackCnt + whiteCnt << '\n';
    
    return 0;
}

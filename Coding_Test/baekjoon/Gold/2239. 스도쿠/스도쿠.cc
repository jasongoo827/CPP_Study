#include <iostream>
#include <vector>

using namespace std;

int board[9][9];
bool row[9][10];
bool col[9][10];
bool box[9][10];
vector<pair<int, int>> blank;

void dfs(int idx)
{
    if (idx == blank.size())
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
                cout << board[i][j];
            cout << '\n';
        }
        exit(0);
    }
    
    int y = blank[idx].first;
    int x = blank[idx].second;
    int b = (y / 3) * 3 + x / 3;
    
    for (int num = 1; num <= 9; ++num)
    {
        if (row[y][num] || col[x][num] || box[b][num])
            continue;
        
        row[y][num] = col[x][num] = box[b][num] = true;
        board[y][x] = num;
        
        dfs(idx + 1);
        
        row[y][num] = col[x][num] = box[b][num] = false;
        board[y][x] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    char c;
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            cin >> c;
            board[i][j] = c - '0';
            if (board[i][j] != 0)
            {
                int n = board[i][j];
                row[i][n] = true;
                col[j][n] = true;
                box[(i / 3) * 3 + j / 3][n] = true;
            }
            else
                blank.push_back({i, j});
        }
    }
    
    dfs(0);
    
    return 0;
}

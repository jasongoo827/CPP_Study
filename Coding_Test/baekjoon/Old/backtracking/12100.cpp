#include <iostream>
#include <vector>

using namespace std;

// boj 12100

int n;
int ret = 0;

int getMaxBlock(vector<vector<int>>& board)
{
    int maxBlock = -1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            maxBlock = max(maxBlock, board[i][j]);
    return maxBlock;
}

bool isMovePossible(vector<vector<int>>& board, int dir)
{
    if (dir == 0)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (board[i][j] != 0)
                {
                    if (board[i][j - 1] == 0)
                        return true;
                    if (board[i][j - 1] == board[i][j])
                        return true;
                }
            }
        }
    }
    else if (dir == 1)
    {
        for (int j = 0; j < n; j++)
        {
            for (int i = 1; i < n; i++)
            {
                if (board[i][j] != 0)
                {
                    if (board[i - 1][j] == 0)
                        return true;
                    if (board[i - 1][j] == board[i][j])
                        return true;
                }
            }
        }
    }
    else if (dir == 2)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n - 1; ++j)
            {
                if (board[i][j] != 0)
                {
                    if (board[i][j + 1] == 0)
                        return true;
                    if (board[i][j + 1] == board[i][j])
                        return true;
                }
            }
        }
    }
    else if (dir == 3)
    {
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n - 1; i++)
            {
                if (board[i][j] != 0)
                {
                    if (board[i + 1][j] == 0)
                        return true;
                    if (board[i + 1][j] == board[i][j])
                        return true;
                }
            }
        }
    }
    return false;
}

vector<int> getMoveDir(vector<vector<int>>& board)
{
    vector<int> dirVec;
    for (int dir = 0; dir < 4; ++dir)
    {
        if (isMovePossible(board, dir))
            dirVec.push_back(dir);
    }
    return dirVec;
}

vector<vector<int>> rotate90(vector<vector<int>>& board)
{
    vector<vector<int>> rotated(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            rotated[j][n - 1 - i] = board[i][j];
    return rotated;
}

vector<vector<int>> moveLeft(vector<vector<int>>& board)
{
    vector<vector<int>> newBoard(n, vector<int>(n));
    
    for (int i = 0; i < n; ++i)
    {
        vector<int> row;
        for (int j = 0; j < n; ++j)
            if (board[i][j] != 0)
                row.push_back(board[i][j]);
        
        vector<int> merged;
        for (int k = 0; k < row.size(); ++k)
        {
            if (k < row.size() - 1 && row[k] == row[k+1])
            {
                merged.push_back(row[k] * 2);
                k++;
            }
            else
                merged.push_back(row[k]);
        }
        
        for (int j = 0; j < merged.size(); ++j)
            newBoard[i][j] = merged[j];
    }
    return newBoard;
}

vector<vector<int>> move(vector<vector<int>>& board, int dir)
{
    vector<vector<int>> temp = board;
    
    // 왼쪽 이동으로 통일하기 위해 회전
    for (int i = 0; i < dir; ++i)
        temp = rotate90(temp);
    
    // 왼쪽 이동 수행
    temp = moveLeft(temp);
    
    for (int i = 0; i < (4 - dir) % 4; ++i)
        temp = rotate90(temp);
    
    return temp;
}

void dfs(vector<vector<int>>& board, int depth)
{
    if (depth == 5)
    {
        ret = max(ret, getMaxBlock(board));
        return;
    }

    vector<int> dir = getMoveDir(board);
    if (dir.size() == 0)
    {
        ret = max(ret, getMaxBlock(board));
        return;
    }

    for (int d: dir)
    {
        vector<vector<int>> newBoard = move(board, d);
        dfs(newBoard, depth + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> board[i][j];
    
    dfs(board, 0);
    cout << ret << '\n';

    return 0;
}
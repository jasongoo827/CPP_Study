#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int n, m;

int bfs(int y, int x, int id, vector<string>& board, vector<vector<int>>& groupId)
{
    queue<pair<int, int>> q;
    q.push({y, x});
    groupId[y][x] = id;
    int size = 1;
    
    while (!q.empty())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        
        for (int d = 0; d < 4; ++d)
        {
            int ny = dy[d] + curY;
            int nx = dx[d] + curX;
            
            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            if (board[ny][nx] == '0' && groupId[ny][nx] == 0)
            {
                groupId[ny][nx] = id;
                q.push({ny, nx});
                size++;
            }
        }
    }
    return size;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    vector<string> board(n);
    for (int i = 0; i < n; ++i)
        cin >> board[i];
    
    vector<vector<int>> groupId(n, vector<int>(m, 0));
    vector<int> groupSize;
    
    int current = 1;
    groupSize.push_back(0);
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (board[i][j] == '0' && groupId[i][j] == 0)
            {
                int size = bfs(i, j, current, board, groupId);
                groupSize.push_back(size);
                current++;
            }
        }
    }
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (board[i][j] == '1')
            {
                set<int> adjGroup;
                for (int d = 0; d < 4; ++d)
                {
                    int ny = i + dy[d];
                    int nx = j + dx[d];
                    if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                        continue;
                    if (board[ny][nx] == '0')
                        adjGroup.insert(groupId[ny][nx]);
                }
                int total = 1;
                for (int id: adjGroup)
                    total += groupSize[id];
                cout << total % 10;
            }
            else
                cout << 0;
        }
        cout << '\n';
    }
    
    return 0;
}
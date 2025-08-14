#include <iostream>
#include <queue>

using namespace std;

// boj 9328

int t, h, w;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    
    while (t--)
    {
        cin >> h >> w;

        vector<vector<char>> board(h, vector<char>(w));
        vector<vector<bool>> visited(h, vector<bool>(w, false));
        // vector<vector<pair<int, int>>> doors(26);
        queue<pair<int, int>> doors[26];

        queue<pair<int, int>> q;
        bool key[26] = {false};

        for (int i = 0; i < h; ++i)
        {
            string line;
            cin >> line;
            
            for (int j = 0; j < w; ++j)
                board[i][j] = line[j];
        }
            
        string keyStr;
        cin >> keyStr;

        if (keyStr != "0")
        {
            for (char k: keyStr)
                key[k - 'a'] = true;;
        }
        
        int docs = 0;
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                char pos = board[i][j];
                if ((i == 0 || i == h - 1 || j == 0 || j == w - 1) && pos != '*')
                {
                    if (isupper(pos))
                    {
                        if (key[pos - 'A'])
                        {
                            q.push({i, j});
                            visited[i][j] = true;
                        }
                        else
                            doors[pos - 'A'].push({i, j});
                    }
                    else
                    {
                        if (islower(pos))
                            key[pos - 'a'] = true;
                        else if (pos == '$')
                            docs++;
                        q.push({i, j});
                        visited[i][j] = true;
                    }
                }
            }
        }

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();

            for (int dir = 0; dir < 4; ++dir)
            {
                int ny = cur.first + dy[dir];
                int nx = cur.second + dx[dir];
                
                if (ny < 0 || nx < 0 || ny >= h || nx >= w)
                continue;
                
                char pos = board[ny][nx];
                
                if (visited[ny][nx] || pos == '*')
                    continue;

                if (isupper(pos))
                {
                    if (key[pos - 'A'])
                    {
                        q.push({ny, nx});
                        visited[ny][nx] = true;
                    }
                    else
                        doors[pos - 'A'].push({ny, nx});
                }
                else
                {
                    if (islower(pos))
                    {
                        if (!key[pos - 'a'])
                        {
                            key[pos - 'a'] = true;
                            while (!doors[pos - 'a'].empty())
                            {
                                q.push(doors[pos - 'a'].front());
                                doors[pos - 'a'].pop();
                            }
                        }
                    }
                    else if (pos == '$')
                        docs++;
    
                    q.push({ny, nx});
                    visited[ny][nx] = true;
                }
            }
        }

        cout << docs << '\n';
    }

    return 0;
}
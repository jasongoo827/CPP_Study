#include <iostream>
#include <vector>

using namespace std;

int n, m;
int board[500][500];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> board[i][j];
    
    vector<vector<pair<int, int>>> blocks = {
        {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
        {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
        {{0, 0}, {1, 0}, {0, 1}, {1, 1}},
        {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
        {{1, 0}, {1, 1}, {1, 2}, {0, 2}},
        {{0, 0}, {0, 1}, {1, 1}, {2, 1}},
        {{1, 0}, {0, 0}, {0, 1}, {0, 2}},
        {{2, 0}, {2, 1}, {1, 1}, {0, 1}},
        {{0, 0}, {0, 1}, {0, 2}, {1, 2}},
        {{2, 0}, {1, 0}, {0, 0}, {0, 1}},
        {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
        {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
        {{1, 0}, {1, 1}, {0, 1}, {0, 2}},
        {{2, 0}, {1, 0}, {1, 1}, {0, 1}},
        {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
        {{0, 0}, {0, 1}, {0, 2}, {1, 1}},
        {{0, 0}, {1, 0}, {2, 0}, {1, 1}},
        {{1, 0}, {1, 1}, {1, 2}, {0, 1}},
        {{0, 1}, {1, 1}, {2, 1}, {1, 0}}
    };
    
    int ret = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            for (auto& block: blocks)
            {
                bool isRange = true;
                int sum = 0;
                for (auto& [x, y]: block)
                {
                    int ny = i + y;
                    int nx = j + x;
                    if (ny >= n || nx >= m)
                    {
                        isRange = false;
                        break;
                    }
                    sum += board[ny][nx];
                }
                if (isRange)
                    ret = max(sum, ret);
            }
        }
    }
    cout << ret << '\n';
    
    return 0;
}

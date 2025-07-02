#include <iostream>
#include <vector>

using namespace std;

// boj 11403

int n;
const int INF = 1e9;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }

    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (graph[i][j] > graph[i][k] + graph[k][j])
                    graph[i][j] = 1;
            }   
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (graph[i][j] != INF)
                cout << graph[i][j] << " ";
            else
                cout << 0 << " ";
        }
        cout << '\n';
    }

    return 0;
}
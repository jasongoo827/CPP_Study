#include <bits/stdc++.h>

using namespace std;

int n, m;
int here, there, cost;

const int INF = 987654321;
const int MAX_V = 101;

int adj[MAX_V][MAX_V];
int via[MAX_V][MAX_V];

void floyd()
{
    for (int i = 1; i <= n; ++i) adj[i][i] = 0;

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (adj[i][k] != INF && adj[k][j] != INF)
                    if (adj[i][j] > adj[i][k] + adj[k][j])
                    {
                        adj[i][j] = adj[i][k] + adj[k][j];
                        via[i][j] = k;
                    }

}

void reconstruct(int u, int v, vector<int>& path)
{
    if (via[u][v] == -1)
    {
        path.push_back(u);
        if (u != v) path.push_back(v);
    }
    else
    {
        int w = via[u][v];
        reconstruct(u, w, path);
        path.pop_back();
        reconstruct(w, v, path);
    }
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            if (i == j) adj[i][j] = 0;
            else adj[i][j] = INF;
            via[i][j] = -1;
        }

    while (m--)
    {
        cin >> here >> there >> cost;
        if (adj[here][there] > cost)
            adj[here][there] = cost;
    }

    floyd();

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (adj[i][j] == INF) cout << 0 << " ";
            else cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            vector<int> path;

            reconstruct(i, j, path); 

            if (adj[i][j] == INF || i == j)
            {
                cout << 0 << " ";
                continue;
            }
            else
            {
                cout << path.size() << " ";
                for (int k = 0; k < (int)path.size(); ++k)
                    cout << path[k] << " ";
                cout << endl;
            }
        }
    }

    return 0;
}
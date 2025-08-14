#include <bits/stdc++.h>

using namespace std;

int n, m;
int here, there, cost;

const int INF = 987654321;
const int MAX_V = 101;

int adj[MAX_V][MAX_V];

void floyd()
{
    for (int i = 1; i <= n; ++i) adj[i][i] = 0;

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (adj[i][k] != INF && adj[k][j] != INF)
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            adj[i][j] = INF;

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

    return 0;
}
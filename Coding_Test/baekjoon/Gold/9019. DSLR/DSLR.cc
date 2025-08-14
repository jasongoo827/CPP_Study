#include <iostream>
#include <queue>

using namespace std;

int t;

void bfs(int start, int end)
{
    queue<int> q;

    vector<bool> visited(10000);
    vector<string> path(10000);

    q.push(start);
    visited[start] = true;
    path[start] = "";

    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        
        if (n == end)
        {
            cout << path[n] << '\n';
            return;
        }

        int d = (n * 2) % 10000;
        int s = (n == 0) ? 9999 : n - 1;
        int l = (n / 1000) + (n % 1000) * 10;
        int r = (n % 10) * 1000 + (n / 10);
        
        if (!visited[d])
        {
            q.push(d);
            visited[d] = true;
            path[d] = path[n] + "D";
        }
        
        if (!visited[s])
        {
            q.push(s);
            visited[s] = true;
            path[s] = path[n] + "S";
        }

        if (!visited[l])
        {
            q.push(l);
            visited[l] = true;
            path[l] = path[n] + "L";
        }
        
        if (!visited[r])
        {
            q.push(r);
            visited[r] = true;
            path[r] = path[n] + "R";
        }
    }
    cout << path[end] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> t;

    int a, b;
    for (int i = 0; i < t; ++i)
    {
        cin >> a >> b;
        bfs(a, b);
    }

    return 0;
}
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

// boj 16928

int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    unordered_map<int, int> ladder_snake;

    for (int i = 0; i < n + m; ++i)
    {
        int x, y;
        cin >> x >> y;
        ladder_snake.insert({x, y});
    }

    queue<int> q;
    int ret[101] = {0, };
    bool visited[101] = {false, };

    q.push(1);
    ret[1] = 0;
    visited[1] = true;

    while (!q.empty())
    {
        int here = q.front();
        q.pop();

        for (int i = 1; i <= 6; ++i)
        {
            int there = here + i;
            if (there > 100)
                continue;
            if (ladder_snake.find(there) != ladder_snake.end())
                there = ladder_snake[there];
            if (!visited[there])
            {
                q.push(there);
                visited[there] = true;
                ret[there] = ret[here] + 1;
            }
        }
    }

    cout << ret[100] << '\n';

    return 0;
}
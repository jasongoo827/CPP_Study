#include <iostream>

using namespace std;

// boj 18111
int n, m, b;
int graph[500][500];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> b;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> graph[i][j];
    
    int ret = 1e9;
    int height = 0;
    for (int h = 0; h <= 256; ++h)
    {
        int cnt = 0;
        int t = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                int diff = graph[i][j] - h;
                (diff > 0) ? t += 2 * diff : t -= diff;
                cnt += diff;
            }
        }
        if (cnt + b >= 0)
        {
            if (ret > t || (ret == t && h > height))
            {
                ret = t;
                height = h;
            }
        }
    }
    cout << ret << " " << height << '\n';

    return 0;
}
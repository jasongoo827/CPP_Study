#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int,int>> table;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int s, t;
    for (int i = 0; i < n; ++i)
    {
        cin >> s >> t;
        table.push_back({s, t});
    }
}

void solve()
{
    priority_queue<int, vector<int>> pq;
    sort(table.begin(), table.end());

    for (int i = 0; i < n; ++i)
    {
        if (!pq.empty())
        {
            if (table[i].first >= -pq.top())
                pq.pop();
            pq.push(-table[i].second);
        }
        else
            pq.push(-table[i].second);
    }
    cout << pq.size();
}

int main(void)
{
    input();    
    solve();

    return (0);
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> v;

bool cmp(pair<int, int>& p1, pair<int, int>& p2)
{
    return p1.second < p2.second || (p1.second == p2.second && p1.first < p2.first);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    
    for (int i = 0; i < n; ++i)
    {
        int s, t;
        cin >> s >> t;
        v.push_back({s, t});
    }
    sort(v.begin(), v.end(), cmp);
    
    int cnt = 0, last = 0;
    for (auto& [start, end]: v)
    {
        if (start >= last)
        {
            last = end;
            cnt++;
        }
    }
    
    cout << cnt << '\n';
    return 0;
}
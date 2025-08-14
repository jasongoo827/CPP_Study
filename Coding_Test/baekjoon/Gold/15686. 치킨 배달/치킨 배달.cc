#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int n, m;
int ret = INT_MAX;
int board[50][50];
vector<pair<int, int>> chickens;
vector<pair<int, int>> houses;

void solve(vector<int>& comb)
{
    int sum = 0;
    for (auto& house: houses)
    {
        int minDist = INT_MAX;
        for (auto& idx: comb)
        {
            int diff = abs(chickens[idx].first - house.first) + abs(chickens[idx].second - house.second);
            minDist = min(minDist, diff);
        }
        sum += minDist;
    }
    ret = min(ret, sum);
}

void dfs(int start, vector<int>& v)
{
    if (v.size() == m)
    {
        solve(v);
        return;
    }
    
    for (int i = start; i < chickens.size(); ++i)
    {
        v.emplace_back(i);
        dfs(i + 1, v);
        v.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
                houses.push_back({i, j});
            else if (board[i][j] == 2)
                chickens.push_back({i, j});
        }
    } 
    
    vector<int> v;
    
    dfs(0, v);
    
    cout << ret << '\n';
    
    return 0;
}
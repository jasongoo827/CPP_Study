#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int N;
int ret = INT_MAX;
int startlink[20][20];
bool visited[20];

void solve()
{
    vector<int> teamA, teamB;
    for (int i = 0; i < N; ++i)
    {
        if (visited[i]) teamA.push_back(i);
        else teamB.push_back(i);
    }

    int sumA = 0, sumB = 0;

    for (int i = 0; i < teamA.size(); ++i)
    {
        for (int j = i + 1; j < teamA.size(); ++j)
        {
            int a = teamA[i], b = teamA[j];
            sumA += startlink[a][b] + startlink[b][a];
        }
    }

    for (int i = 0; i < teamB.size(); ++i)
    {
        for (int j = i + 1; j < teamB.size(); ++j)
        {
            int a = teamB[i], b = teamB[j];
            sumB += startlink[a][b] + startlink[b][a];
        }
    }

    ret = min(ret, abs(sumA - sumB));
}

void dfs(int idx, int count)
{
    if (count == N / 2)
    {
        solve();
        return;
    }

    for (int i = idx; i < N; ++i)
    {
        visited[i] = true;
        dfs(i + 1, count + 1);
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            cin >> startlink[i][j];
    }

    visited[0] = true;
    dfs(1, 1);
    cout << ret << '\n';
    
    return 0;
}
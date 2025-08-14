#include <iostream>
#include <vector>

using namespace std;

// boj 10974

int n;
bool visited[9];

void dfs(int picked, vector<int>& v)
{
    if (picked == n)
    {
        for (int num: v)
            cout << num << " ";
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            visited[i] = true;
            v.push_back(i);
            dfs(picked + 1, v);
            v.pop_back();
            visited[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<int> v;
    dfs(0, v);

    return 0;
}
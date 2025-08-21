#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotateWheel(vector<vector<int>>& wheel, vector<bool>& visited, int num, int dir)
{
    // n 이 0, s가 1
    visited[num - 1] = true;
    if (num - 1 > 0 && !visited[num - 2])
    {
        if (wheel[num - 1][6] != wheel[num - 2][2])
            rotateWheel(wheel, visited, num - 1, -dir);
    }
    if (num + 1 < 5 && !visited[num])
    {
        if (wheel[num - 1][2] != wheel[num][6])
            rotateWheel(wheel, visited, num + 1, -dir);
    }
    vector<int> tmp(8);
    for (int i = 0; i < 8; ++i)
        tmp[i] = wheel[num - 1][(i - dir + 8) % 8];
    for (int i = 0; i < 8; ++i)
        wheel[num - 1][i] = tmp[i];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<vector<int>> wheel(4, vector<int>(8, 0));
    vector<bool> visited(4, false);
    for (int i = 0; i < 4; ++i)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); ++j)
            wheel[i][j] = s[j] - '0';
    }
    
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        int num;
        int dir;
        cin >> num >> dir;
        rotateWheel(wheel, visited, num, dir);
        fill(visited.begin(), visited.end(), false);
    }

    int ret = 0;
    
    if (wheel[0][0] == 1)
        ret += 1;
    if (wheel[1][0] == 1)
        ret += 2;
    if (wheel[2][0] == 1)
        ret += 4;
    if (wheel[3][0] == 1)
        ret += 8;
    cout << ret << '\n';
    
    return 0;
}
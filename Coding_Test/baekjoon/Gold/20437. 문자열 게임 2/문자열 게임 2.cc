#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int t;
string w;
int k;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> t;
    while (t--)
    {
        cin >> w >> k;
        
        vector<int> pos[26];
        int minLen = INT_MAX;
        int maxLen = -1;
        
        for (int i = 0; i < w.length(); ++i)
            pos[w[i] - 'a'].push_back(i);
        
        for (int i = 0; i < 26; ++i)
        {
            if (pos[i].size() < k)
                continue;
            
            for (int j = 0; j < pos[i].size() - k + 1; ++j)
            {
                int len = pos[i][j + k - 1] - pos[i][j] + 1;
                minLen = min(minLen, len);
                maxLen = max(maxLen, len);
            }
        }
        if (minLen == INT_MAX && maxLen == -1)
            cout << -1 << '\n';
        else
            cout << minLen << " " << maxLen << '\n';
    }
    
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i)
            cin >> v[i].first >> v[i].second;
        sort(v.begin(), v.end());
        
        int minVal = v[0].second;
        int ret = 1;
        
        for (int i = 1; i < n; ++i)
        {
            if (v[i].second < minVal)
            {
                ret++;
                minVal = v[i].second;
            }
        }
        cout << ret << '\n';
    }
    
    return 0;
}
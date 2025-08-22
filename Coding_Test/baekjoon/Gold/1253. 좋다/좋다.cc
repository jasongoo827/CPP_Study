#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

bool isGood(vector<int>& v, int idx)
{
    int target = v[idx];
    int l = 0;
    int r = v.size() - 1;
    
    while (l < r)
    {
        if (l == idx)
        {
            l++;
            continue;            
        }
        if (r == idx)
        {
            r--;
            continue;
        }        
        int sum = v[l] + v[r];
        if (sum == target)
            return true;
        else if (sum < target)
            l++;
        else
            r--;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    vector<int> v(n);
    
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());
    
    int ret = 0;
    for (int i = 0; i < n; ++i)
    {
        if (isGood(v, i))
            ret++;
    }
    cout << ret << '\n';
    
    return 0;
}
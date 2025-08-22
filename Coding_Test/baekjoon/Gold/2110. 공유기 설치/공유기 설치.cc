#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c;

bool canPlace(vector<int>& houses, int minDist)
{
    int cnt = 1;
    int lastPos = houses[0];
    
    for (int i = 1; i < houses.size(); ++i)
    {
        if (minDist <= houses[i] - lastPos)
        {
            cnt++;
            lastPos = houses[i];
            if (cnt == c)
                return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> c;
    vector<int> v(n);
    
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());
    
    int left = 0;
    int right = v[n - 1] - v[0];
    int ret;
    
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (canPlace(v, mid))
        {
            ret = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    cout << ret << '\n';
        
    return 0;
}
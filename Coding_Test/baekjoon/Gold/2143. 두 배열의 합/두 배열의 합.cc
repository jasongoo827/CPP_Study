#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int t, n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> t;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    
    
    unordered_map<int, int> aSum;
    unordered_map<int, int> bSum;
    long long ret = 0;
    for (int i = 0; i < n; ++i)
    {
        int sum = 0;
        for (int j = i; j < n; ++j)
        {
            sum += a[j];
            aSum[sum]++;
        }
    }
    for (int i = 0; i < m; ++i)
    {
        int sum = 0;
        for (int j = i; j < m; ++j)
        {
            sum += b[j];
            if (aSum.count(t - sum))
                ret += aSum[t - sum];
        }
    }
    cout << ret << '\n';
    
    return 0;
}
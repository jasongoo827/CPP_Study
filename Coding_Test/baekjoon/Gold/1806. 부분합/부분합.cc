#include <iostream>
#include <vector>

using namespace std;

int n, s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s;
    vector<int> arr(n);    
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int l = 0;
    int r = 0;
    int sum = 0;
    int ret = 1e6;
    
    while (true)
    {
        if (sum >= s)
        {
            ret = min(ret, r - l);
            sum -= arr[l++];
        }
        else if (r == n)
            break;
        else
            sum += arr[r++];
    }
    
    cout << (ret == 1e6 ? 0 : ret) << '\n';
    
    return 0;
}
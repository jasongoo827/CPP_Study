#include <iostream>
#include <vector>

using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    
    if (n == 1)
    {
        cout << "0\n";
        return 0;
    }
    
    vector<bool> isPrime(n + 1, true);
    
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; ++i)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    
    vector<int> v;
    v.reserve(n / 2);
    for (int i = 2; i <= n; ++i)
    {
        if (isPrime[i])
            v.push_back(i);
    }
    
    int m = v.size();
    int l = 0;
    int r = 0;
    int sum = 0;
    int ret = 0;
    
    while (true)
    {
        if (sum >= n)
        {
            if (sum == n)
                ret++;
            sum -= v[l++];
        }
        else if (r == m)
            break;
        else
            sum += v[r++];
    }
    cout << ret << '\n';
    
    return 0;
}

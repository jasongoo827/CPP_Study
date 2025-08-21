#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, d, k, c;
    cin >> n >> d >> k >> c;
    vector<int> v(n);
    
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    int sushi[3001] = {0};
    int variety = 0;
    int ret = 0;
    
    for (int i = 0; i < k; ++i) {
        if (sushi[v[i]]++ == 0) 
            variety++;
    }
    
    ret = variety + (sushi[c] == 0 ? 1 : 0);
    
    for (int i = 1; i < n; ++i) {
        if (--sushi[v[i - 1]] == 0)
            variety--;
        
        if (sushi[v[(i + k - 1) % n]]++ == 0)
            variety++;
        
        ret = max(ret, variety + (sushi[c] == 0 ? 1 : 0));
    }
    
    cout << ret << '\n';
    
    return 0;
}
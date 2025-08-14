#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    
    vector<int> a(n);
    vector<int> b(n);
    
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    
    sort(a.begin(), a.end(), [](int x, int y){
        return x > y;
    });
    sort(b.begin(), b.end());
    
    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += (a[i] * b[i]);
    
    cout << sum << '\n';
    
    return 0;
}

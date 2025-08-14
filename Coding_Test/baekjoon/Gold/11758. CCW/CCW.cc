#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    long long cross = 1LL * (x2 - x1) * (y3 - y2) - 1LL * (y2 - y1) * (x3 - x2);
    if (cross > 0)
        cout << 1 << '\n';
    else if (cross < 0)
        cout << -1 << '\n';
    else
        cout << 0 << '\n';
    
    return 0;
}

#include <iostream>

using namespace std;

using ll = long long;

ll cal(int a, int b, int c)
{
    if (b == 0)
        return 1;
    ll half = cal(a, b / 2, c);
    ll ret = (half * half) % c;
    if (b & 1)
        ret = (ret * a) % c;
    return ret;
}

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a, b, c;
    cin >> a >> b >> c;
    cout << cal(a, b, c) << '\n';
    
    return 0;
}

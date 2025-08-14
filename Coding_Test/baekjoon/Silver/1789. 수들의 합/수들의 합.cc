#include <iostream>

using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long s;
    cin >> s;
    long long sum = 0;
    int n = 0;

    for (int i = 1; ; ++i)
    {
        if (sum + i > s) break;
        sum += i;
        n++;
    }
    cout << n;
    
    return 0;
}

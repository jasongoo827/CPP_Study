#include <iostream>
#include <cmath>

using namespace std;

// boj

// 100,000,000
int n;

int getDigit(int num)
{
    int cnt = 0;
    
    while (num != 0)
    {
        num /= 10;
        cnt++;
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    int cur = getDigit(n);
    int ret = 0;

    ret += ((n - pow(10, cur - 1)) + 1) * cur;
    while (cur > 1)
    {
        ret += (pow(10, cur - 1) - pow(10, cur - 2)) * (cur - 1);
        cur--;
    }

    cout << ret << '\n';

    return 0;
}
#include <iostream>

using namespace std;

// boj 1107

int n, m;
int ret = 1e9;
int nDigit;
bool possible[10];

int getDigit(int num)
{
    if (num == 0)
        return 1;

    int cnt = 0;
    while (num != 0)
    {
        num /= 10;
        cnt++;
    }
    return cnt;
}

bool isPossible(int num)
{
    if (num == 0)
        return possible[num];

    while (num != 0)
    {
        if (!possible[num % 10])
            return false;
        num /= 10;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    fill(possible, possible + 10, true);
    for (int i = 0; i < m; ++i)
    {
        int num;
        cin >> num;
        possible[num] = false;
    }
    ret = min(ret, abs(n - 100));

    for (int i = 0; i <= 1000000; ++i)
    {
        if (isPossible(i))
            ret = min(ret, abs(i - n) + getDigit(i));
    }

    cout << ret << '\n';

    return 0;
}
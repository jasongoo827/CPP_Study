#include <iostream>

using namespace std;

// boj 1790

int n, k;

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

int pow(int num, int k)
{
    int ret = 1;

    for (int i = 0; i < k; ++i)
        ret *= num;
    return ret;    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    
    int cur = getDigit(n);
    int stride = 9;
    int len = 0;

    for (int i = 1; i <= cur; ++i)
    {
        int curPow = pow(10, i);
        int prevPow = pow(10, i - 1);

        if (n < curPow)
            len = (n - prevPow + 1) * i;
        else
            len = stride * i;

        if (k > len)
            k -= len;
        else
        {
            int j = k / i;
            int kth = k % i;
            int num;

            if (kth == 0)
            {
                num = prevPow + j - 1;
                kth = i;
            }
            else
                num = prevPow + j;
                
            string s = to_string(num);
            cout << s[kth - 1] << '\n';
            return 0;
        }
        stride *= 10;
    }
    cout << -1 << '\n';

    return 0;
}
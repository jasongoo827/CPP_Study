#include <iostream>
#include <algorithm>

using namespace std;

int n, k;

int findKthNum(int n, int k)
{
    int left = 1, right = n * n;
    int ret;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        int cnt = 0;

        for (int i = 1; i <= n; ++i)
            cnt += min(mid / i, n);

        if (cnt >= k)
        {
            ret = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    cout << findKthNum(n, k);   
}
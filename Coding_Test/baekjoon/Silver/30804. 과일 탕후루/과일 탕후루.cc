#include <iostream>
#include <vector>

using namespace std;

// boj 30804

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    int r = 0, l = 0;
    int type = 0;
    int ret = 0;
    int fruitCount[11] = {0,};

    while (r < n)
    {
        int right = v[r];
        fruitCount[right]++;
        if (fruitCount[right] == 1)
            type++;
        if (type > 2)
        {
            while (type > 2)
            {
                int left = v[l];
                fruitCount[left]--;
                if (fruitCount[left] == 0)
                    type--;
                l++;
            }
        }
        ret = max(ret, r - l + 1);
        r++;
    }
    cout << ret << '\n';

    return 0;
}
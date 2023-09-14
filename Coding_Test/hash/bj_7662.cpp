#include <iostream>
#include <set>
#define endl '\n'

using namespace std;

int t, k;

void solve()
{
    cin >> t;

    while (t--)
    {
        char c;
        int n;
        cin >> k;
        multiset<int> ms;
        while (k--)
        {
            cin >> c >> n;
            if (c == 'I')
                ms.insert(n);
            else if (c == 'D')
            {
                if (ms.empty()) continue;
                if (n == 1)
                {
                    auto it = ms.end();
                    ms.erase(--it);
                }
                else if (n == -1)
                    ms.erase(ms.begin());
            }
        }
        if (ms.empty())
            cout << "EMPTY" << endl;
        else
        {
            auto it = ms.end();
            cout << *(--it) << " " << *(ms.begin()) << endl;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return (0);
}
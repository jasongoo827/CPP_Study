#include <iostream>
#include <string>
#include <map>

using namespace std;

int n, m;
map<string, bool> listmap;

void solve()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    int cnt = 0;
    string s;
    while (n--)
    {
        cin >> s;
        listmap.insert(make_pair(s, true));
    }
    while (m--)
    {
        cin >> s;
        if (listmap[s] == true) cnt++;
    }
    cout << cnt;
}

int main(void)
{
    solve();
}
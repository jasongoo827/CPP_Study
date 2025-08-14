#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#define endl '\n'

using namespace std;

int n, m;
int cnt = 0;
map<string, bool> listmap;
vector<string> ret;

void solve()
{
    cin >> n >> m;

    while (n--)
    {
        string s;
        cin >> s;
        listmap.insert(make_pair(s, true));
    }

    while (m--)
    {
        string s;
        cin >> s;
        if (listmap[s] == true)
        {
            cnt++;
            ret.push_back(s);
        }
    }
}

int main(void)
{
    solve();

    cout << cnt << endl;
    sort(ret.begin(), ret.end());
    for (auto& str: ret)
        cout << str << endl;

    return (0);
}
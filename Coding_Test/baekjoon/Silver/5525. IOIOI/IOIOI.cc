#include <iostream>

using namespace std;

int n, m;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m >> s;
    
    int cnt = 0;
    int ret = 0;
    for (int i = 1; i < m - 1;)
    {
        if (s[i - 1] == 'I' && s[i] == 'O' && s[i + 1] == 'I')
        {
            cnt++;
            if (cnt == n)
            {
                ret++;
                cnt --;
            }
            i += 2;
        }
        else
        {
            cnt = 0;
            i++;
        }
    }
    cout << ret << '\n';
    
    return 0;
}

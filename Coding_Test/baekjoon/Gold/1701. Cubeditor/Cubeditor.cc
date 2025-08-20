#include <iostream>
#include <vector>
#include <string>

using namespace std;

string s;

int getMaxPi(const string& suffix)
{
    int maxPi = 0;
    int m = suffix.length();
    vector<int> pi(m, 0);
   
    int j = 0;
    for (int i = 1; i < m; ++i)
    {
        while (j > 0 && suffix[i] != suffix[j])
            j = pi[j - 1];
        if (suffix[i] == suffix[j])
        {
            j++;
            pi[i] = j;
            maxPi = max(maxPi, pi[i]);
        }
    }
    return maxPi;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> s;
    int ret = 0;
    
    for (int i = 0; i < s.length(); ++i)
    {
        string suffix = s.substr(i);
        ret = max(ret, getMaxPi(suffix));
    }
    cout << ret << '\n';
    
    return 0;
}
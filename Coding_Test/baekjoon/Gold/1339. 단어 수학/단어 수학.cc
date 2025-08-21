#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getWeight(int n)
{
    int ret = 1;
    for (int i = 0; i < n; ++i)
        ret *= 10;
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    int alph[26] = {0};
    vector<pair<int, char>> weight;
    
    vector<string> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        for (int j = 0; j < v[i].length(); ++j)
        {
            alph[v[i][j] - 'A'] += getWeight(v[i].length() - j - 1);        
        }
    }
    
    for (int i = 0; i < 26; ++i)
    {
        if (alph[i] > 0)
            weight.push_back({alph[i], i + 'A'});
    }
    sort(weight.rbegin(), weight.rend());
    
    int ret = 0;
    int digit = 9;
    for (int i = 0; i < weight.size(); ++i)
    {
        ret += alph[weight[i].second - 'A'] * digit;
        digit--;
    }
    cout << ret << '\n';
    
    return 0;
}
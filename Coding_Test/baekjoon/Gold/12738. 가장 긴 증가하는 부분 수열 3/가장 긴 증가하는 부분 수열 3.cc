#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> vec;
vector<int> lis;

int getLongestPartial()
{
    for (auto& num: vec)
    {
        auto it = lower_bound(lis.begin(), lis.end(), num);

        if (it == lis.end())
            lis.push_back(num);
        else
            *it = num;
    }
    return static_cast<int>(lis.size());
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    vec.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> vec[i];
    
    cout << getLongestPartial();
}
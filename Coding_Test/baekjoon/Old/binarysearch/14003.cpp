#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int n;
vector<int> vec;
vector<int> indices;
vector<int> lis;

int getLongestPartial()
{
    indices.resize(n);

    for (size_t i = 0; i < vec.size(); ++i)
    {
        auto it = lower_bound(lis.begin(), lis.end(), vec[i]);

        int idx = distance(lis.begin(), it);
        if (it == lis.end())
            lis.push_back(vec[i]);
        else
            *it = vec[i];
        indices[i] = idx;
    }
    return static_cast<int>(lis.size());
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;

    cin >> n;
    vec.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> vec[i];
    
    int lisSize = getLongestPartial(); 
    cout << lisSize << '\n';
    
    vector<int> ret;
    stack<int> st;
    for (int i = n - 1; i >= 0; --i)
    {
        if (indices[i] == lisSize - 1)
        {
            lisSize--;
            st.push(vec[i]);
        }
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}
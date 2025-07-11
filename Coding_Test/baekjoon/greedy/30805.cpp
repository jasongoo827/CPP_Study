#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// boj 30805

int n, m;

int find_found_after(vector<int>& v, int idx, int found)
{
    for (int i = idx; i < v.size(); ++i)
    {
        if (v[i] == found)
            return i;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i)
        cin >> b[i];


    int idxA = 0, idxB = 0;
    vector<int> ret;
    while (true)
    {
        unordered_set<int> sa(a.begin() + idxA, a.end());
        unordered_set<int> sb(b.begin() + idxB, b.end());

        int found = -1;
        for (int i = 100; i >= 1; --i)
        {
            if (sa.count(i) && sb.count(i))
            {
                found = i;
                break;
            }
        }
        if (found == -1)
            break;
        ret.push_back(found);
        
        idxA = find_found_after(a, idxA, found) + 1;
        idxB = find_found_after(b, idxB, found) + 1;
    }
    
    cout << ret.size() << '\n';
    for (int num: ret)
        cout << num << " ";

    return 0;
}
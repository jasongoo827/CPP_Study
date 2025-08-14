#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, s;
vector<int> vec;

void getPartialSum(vector<int>& v, vector<int>& partialV)
{
    int n  = static_cast<int>(v.size());

    for (int i = 0; i < (1 << n); ++i)
    {
        int sum = 0;
        for (int j = 0; j < n; ++j)
        {
            if (i & (1 << j))
                sum += v[j];
        }
        partialV.push_back(sum);
    }
}

long long getPartialCount(const vector<int>& v)
{
    vector<int> left(v.begin(), v.begin() + v.size() / 2);
    vector<int> right(v.begin() + v.size() / 2, v.end());
    vector<int> leftSums, rightSums;
    long long ret = 0;

    getPartialSum(left, leftSums);
    getPartialSum(right, rightSums);

    sort(leftSums.begin(), leftSums.end());
    sort(rightSums.begin(), rightSums.end());

    for (auto& lsum: leftSums)
    {
        auto range = equal_range(rightSums.begin(), rightSums.end(), s - lsum);
        ret += range.second - range.first;
    }
    return ret - (s == 0 ? 1 : 0);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> s;
    vec.resize(n);

    for (int i = 0; i < n; ++i)
        cin >> vec[i];
   
    cout << getPartialCount(vec);
}
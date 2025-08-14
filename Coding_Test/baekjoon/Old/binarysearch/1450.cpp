#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, c;
vector<int> bag;

void getSubsetSum(int s, int e, vector<long long>& subset, ll sum)
{
    if (s > e)
        subset.push_back(sum);
    else
    {
        getSubsetSum(s + 1, e, subset, sum);
        getSubsetSum(s + 1, e, subset, sum + bag[s]);
    }
}

ll solve(const vector<int>& bag)
{
    vector<ll> leftSum, rightSum;
    ll ret = 0;

    getSubsetSum(0, n / 2, leftSum, 0);
    getSubsetSum(n / 2 + 1, n - 1, rightSum, 0);

    sort(rightSum.begin(), rightSum.end());

    for (auto& sum: leftSum)
    {
        auto it = upper_bound(rightSum.begin(), rightSum.end(), c - sum);
        ret += (it - rightSum.begin());
    }
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> c;
    bag.resize(n);

    for (int i = 0; i < n; ++i)
        cin >> bag[i];
    cout << solve(bag);
}
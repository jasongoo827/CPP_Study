#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

using Point = std::pair<int, int>;
using ll = long long;

int n;
vector<Point> v;

ll getMinDist(int s, int e)
{
    long long ret = std::numeric_limits<long long>::max();
    for (int i = s; i < e - 1; ++i)
    {
        for (int j = i + 1; j < e; ++j)
        {
            int dx = v[i].first - v[j].first;
            int dy = v[i].second - v[j].second;
            ret = min(ret, (ll)dx * dx + (ll)dy * dy);
        }
    }
    return ret;
}

ll findClosestPair(int s, int e)
{
    if (e - s <= 3)
        return getMinDist(s, e);
    
    int mid = (s + e) / 2;
    ll d = min(findClosestPair(s, mid), findClosestPair(mid, e));
    
    int mid_x = v[mid].first;
    vector<Point> strip;
    for (int i = s; i < e; ++i)
    {
        int dx = v[i].first - mid_x;
        if ((ll)dx * dx < d)
            strip.push_back(v[i]);
    }
    
    sort(strip.begin(), strip.end(), [](const Point& a, const Point& b){
       return a.second < b.second; 
    });
    
    for (int i = 0; i < strip.size(); ++i)
    {
        for (int j = i + 1; j < strip.size() && (ll)(strip[j].second - strip[i].second) * (strip[j].second - strip[i].second) < d; ++j)
        {
            ll dx = (ll)(strip[i].first - strip[j].first);
            ll dy = (ll)(strip[i].second - strip[j].second);
            d = min(d, dx * dx + dy * dy);
        }
    }
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i].first >> v[i].second;
    
    sort(v.begin(), v.end(), [](const Point& a, const Point& b) {
       return a.first == b.first ? a.second < b.second : a.first < b.first; 
    });
    
    cout << findClosestPair(0, n) << '\n';   
    
    return 0;
}

#include <iostream>

using namespace std;

using ll = long long;

int n;
int height[50];
int cnt[50];

int main(int argc, const char * argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> height[i];

    for (int i = 0; i < n; ++i)
    {
        double max_slope = -1e9;
            
        for (int j = i + 1; j < n; ++j)
        {
            double slope = (height[j] - height[i]) / (double)(j - i);
            if (slope > max_slope)
            {
                max_slope = slope;
                cnt[i]++;
                cnt[j]++;
            }
        }
    }

    int ret = 0;
    for (int num: cnt)
    {
        ret = max(ret, num);
    }
    cout << ret << '\n';
    return 0;
    
    return 0;
}

#include <iostream>

using namespace std;

// boj 2096

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    int input[3];
    int curr_max[3] = {0};
    int prev_max[3] = {0};
    int curr_min[3] = {0};
    int prev_min[3] = {0};

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 3; ++j)
            cin >> input[j];
        curr_max[0] = max(prev_max[0], prev_max[1]) + input[0];
        curr_max[1] = max(max(prev_max[0], prev_max[1]), prev_max[2]) + input[1];
        curr_max[2] = max(prev_max[1], prev_max[2]) + input[2];

        curr_min[0] = min(prev_min[0], prev_min[1]) + input[0];
        curr_min[1] = min(min(prev_min[0], prev_min[1]), prev_min[2]) + input[1];
        curr_min[2] = min(prev_min[1], prev_min[2]) + input[2];

        for (int j = 0; j < 3; ++j)
        {
            prev_max[j] = curr_max[j];
            prev_min[j] = curr_min[j];
        }
    }

    cout << max(max(curr_max[0], curr_max[1]), curr_max[2]) << " " << min(min(curr_min[0], curr_min[1]), curr_min[2]) << '\n';

    return 0;
}
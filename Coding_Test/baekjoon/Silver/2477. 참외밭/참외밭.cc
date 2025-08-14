#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int k;
    int d[6];
    int len[6];
    
    int maxX = 0, maxY = 0;
    int idxX = 0, idxY = 0;
    cin >> k;
    for (int i = 0; i < 6; ++i)
    {
        cin >> d[i] >> len[i];
        if ((d[i] == 1 || d[i] == 2))
        {
            if (maxX < len[i])
            {
                maxX = len[i];
                idxX = i;
            }
        }
        else if (d[i] == 3 || d[i] == 4)
        {
            if (maxY < len[i])
            {
                maxY = len[i];
                idxY = i;
            }
        }
    }
    
    cout << k * (maxX * maxY - (len[(idxX + 3) % 6] * len[(idxY + 3) % 6])) << '\n';
    
    return 0;
}

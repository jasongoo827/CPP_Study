#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Point {
    int h, n, m;
};

int dh[6] = {-1, 1, 0, 0, 0, 0};
int dn[6] = {0, 0, -1, 1, 0, 0}; 
int dm[6] = {0, 0, 0, 0, -1, 1}; 

int main() {
    int M, N, H;
    cin >> M >> N >> H;

    vector<vector<vector<int>>> tomato(H, vector<vector<int>>(N, vector<int>(M)));
    queue<Point> q;

    int total_unripe = 0;

    for (int h = 0; h < H; ++h) {
        for (int n = 0; n < N; ++n) {
            for (int m = 0; m < M; ++m) {
                cin >> tomato[h][n][m];
                if (tomato[h][n][m] == 1) {
                    q.push({h, n, m}); 
                } else if (tomato[h][n][m] == 0) {
                    total_unripe++;
                }
            }
        }
    }

    if (total_unripe == 0) {
        cout << 0 << endl;
        return 0;
    }

    int days = 0;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            Point curr = q.front();
            q.pop();

            for (int d = 0; d < 6; ++d) {
                int nh = curr.h + dh[d];
                int nn = curr.n + dn[d];
                int nm = curr.m + dm[d];

                if (nh >= 0 && nh < H && nn >= 0 && nn < N && nm >= 0 && nm < M && tomato[nh][nn][nm] == 0) {
                    tomato[nh][nn][nm] = 1;
                    q.push({nh, nn, nm});
                    total_unripe--;
                }
            }
        }
        if (!q.empty()) {
            days++;
        }
    }

    if (total_unripe > 0) {
        cout << -1 << endl;
    } else {
        cout << days << endl;
    }

    return 0;
}

#include <iostream>

#define MAX 1025

using namespace std;

int n, m;
int arr[MAX][MAX];
int tree[MAX * 4][MAX * 4];


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> arr[i][j];
}
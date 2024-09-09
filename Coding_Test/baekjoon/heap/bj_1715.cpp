#include <iostream>
#include <queue>
#define endl '\n'

using namespace std;

int n;
priority_queue<int, vector<int>> pq;

void solve()
{
    int sum = 0;
    int cnt = 0;

    while (!pq.empty())
    {
        if (cnt == n -1) break;
        int a = -pq.top();
        pq.pop();
        int b = -pq.top();
        pq.pop();
        sum += (a + b);
        pq.push(-(a + b));
        cnt++;
    }
    cout << sum;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int size;
    for (int i = 0 ;i < n; i++)
    {
        cin >> size;
        pq.push(-size);
    }
    solve();

    return (0);
}
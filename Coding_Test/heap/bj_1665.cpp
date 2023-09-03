#include <iostream>
#include <queue>
#define endl '\n'

using namespace std;

int n;
priority_queue<int, vector<int>> min_heap;
priority_queue<int, vector<int>> max_heap;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
}

void solve()
{
    int num;

    for (int i = 0 ;i < n; ++i)
    {
        cin >> num;
        if (i % 2 == 0)
            max_heap.push(num);
        else
            min_heap.push(-num);
        if (!min_heap.empty() && max_heap.top() > -min_heap.top())
        {
            int max_t = max_heap.top();
            int min_t = -min_heap.top();
            max_heap.pop();
            max_heap.push(min_t);
            min_heap.pop();
            min_heap.push(-max_t);
        }
        cout << max_heap.top() << endl;
    }
}

int main(void)
{
    input();
    solve();
}
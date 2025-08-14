#include <iostream>
#include <stack>
#include <vector>
#define endl '\n'
#define MAX 10000001

using namespace std;

int n;
int arr[MAX];
stack<int> s;
int res[MAX];

void solve()
{
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= arr[i])
            s.pop();
        if (s.empty())
            res[i] = -1;
        else
            res[i] = s.top();
        s.push(arr[i]);
    }

    for (int i = 0; i < n;i++)
        cout << res[i] << " ";
}

int main(void)
{
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    
    solve();
}
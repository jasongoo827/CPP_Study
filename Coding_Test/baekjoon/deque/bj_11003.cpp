    #include <iostream>
    #include <queue>
    #define MAX 5000001

    using namespace std;

    int n, l;
    int arr[MAX];

    struct Data
    {
        int idx;
        int val;
    };

    void input()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        cin >> n >> l;

        for (int i = 1; i <= n; ++i)
            cin >> arr[i];
    }

    void solve()
    {
        deque<Data> dq;

        for (int i = 1; i <= n; ++i)
        {
            if (!dq.empty() && dq.front().idx == i - l)
                dq.pop_front();
            while (!dq.empty() && dq.back().val > arr[i])
                dq.pop_back();
            dq.push_back({i, arr[i]});
            cout << dq.front().val << " ";
        }
    }

    int main(void)
    {
        input();
        solve();

        return (0);
    }
#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

// boj 28707 - 배열을 정점으로 생각했을 때, 최소 비용 구하기
// 배열을 어떤 key로 바꾸느냐에 따라 최적화 다양하게 수행 가능
// 1. 배열 자체를 key로
// 2. string
// 3. bitarray -> 구현 난이도 있음.

int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    string state;
    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        state += '0' + num - 1;
    }
    cin >> m;
    vector<tuple<int, int, int>> costs(m);
    for (int i = 0; i < m; ++i)
    {
        int l, r, c;
        cin >> l >> r >> c;
        costs[i] = {l - 1, r - 1, c};
    }

    string sorted = state;
    sort(sorted.begin(), sorted.end());

    unordered_map<string, int> umap;
    umap[state] = 0;
    
    priority_queue<pair<int, string>, vector<pair<int, string>>> pq;
    pq.push({0, state});

    while (!pq.empty())
    {
        auto cur = pq.top();
        int cost = -cur.first;
        string curState = cur.second;

        pq.pop();

        if (cost > umap[curState])
            continue;

        if (curState == sorted)
        {
            cout << cost << '\n';
            return 0;
        }

        for (int i = 0; i < m; ++i)
        {
            auto& [l, r, c] = costs[i];
            string nextState = curState;
            swap(nextState[l], nextState[r]);

            if (umap.find(nextState) == umap.end() || cost + c < umap[nextState])
            {
                umap[nextState] = cost + c;
                pq.push({-umap[nextState], nextState});
            }    
        }
    }
    cout << -1 << '\n';

    return 0;
}
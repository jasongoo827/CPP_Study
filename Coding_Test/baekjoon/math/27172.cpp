#include <iostream>
#include <vector>

using namespace std;

// boj 27172

int n;
int cards[100001];
bool exists[1000001];
int score[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> cards[i];
        exists[cards[i]] = true;
    }
        
    for (int i = 0; i < n; ++i)
    {
        int card = cards[i];

        for (int mul = card * 2; mul <= 1000001; mul += card)
        {
            if (exists[mul])
            {
                score[card]++;
                score[mul]--;
            }
        }
    }

    for (int i = 0; i < n; ++i)
        cout << score[cards[i]] << " ";

    return 0;
}
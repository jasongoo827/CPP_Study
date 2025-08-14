#include <iostream>
#include <queue>
#define endl '\n'

using namespace std;

int n;
priority_queue<int, vector<int>> pq;

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> n;
    while (n--)
    {
        int input;
        cin >> input;
        if (input > 0)
            pq.push(-input);
        else if (input == 0)
        {
            if (pq.empty() == true)
                cout << "0" << endl;
            else
            {
                cout << -pq.top() << endl;
                pq.pop();
            }
        }
    }
    return (0);
}
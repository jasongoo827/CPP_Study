#include <iostream>
#include <queue>
#include <vector>
#include <stdlib.h>
#define endl '\n'

using namespace std;

struct s_num
{
    bool sign;
    int num;
};

struct cmp
{
    bool operator()(s_num a, s_num b)
    {
        if (a.sign == b.sign)
            return (a.num > b.num);
        else
        {
            if (abs(a.num) == abs(b.num) && a.sign == true && b.sign == false)
                return true;
            else if (abs(a.num) == abs(b.num) && a.sign == false && b.sign == true)
                return false;
            return (abs(a.num) > abs(b.num));
        }
    }
};

int n;
priority_queue<s_num, vector<s_num>, cmp> pq;

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    while (n--)
    {
        int input;
        cin >> input;
        if (input != 0)
        {
            if (input > 0)
                pq.push(s_num{true, input});
            else
                pq.push(s_num{false, -input});
        }
        else
        {
            if (pq.empty() == true)
                cout << "0" << endl;
            else
            {
                if (pq.top().sign == true)
                    cout << pq.top().num << endl;
                else
                    cout << -pq.top().num << endl;
                pq.pop();
            }
        }
    }
}
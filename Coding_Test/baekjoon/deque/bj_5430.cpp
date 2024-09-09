#include <iostream>
#include <string>
#include <string.h>
#define endl '\n'
#define MAX 100001

using namespace std;

int tc, len;
int start_idx, end_idx, arr_size;
string func, arr;
int v[MAX];

bool check_if_num(char c)
{
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

void solve(string func, int len)
{
    cin >> arr;
    int result = 0;
    start_idx = 0;
    end_idx = len - 1;
    arr_size = 0;
    int j = 0;

    // parse array
    for (auto &c: arr)
    {
        if (len == 0) break;
        if (check_if_num(c) == true)
        {
            result *= 10;
            result += (c - '0');
        }
        else if (c == ',' || c == ']')
        {
            v[j++] = result;
            result = 0;
            len--;
            arr_size++;
        }
    }
    // execute function
    bool order = true;
    for (auto &c: func)
    {
        if (c == 'R')
        {
            if (order == true)
                order = false;
            else
                order = true;
        }
        else if (c == 'D')
        {
            if (arr_size == 0)
            {
                cout << "error" << endl;
                return;
            }
            if (order == true)
            {
                start_idx += 1;
                arr_size -= 1;
            }
            else
            {
                end_idx -= 1;
                arr_size -= 1;
            }
        }
    }

    cout << "[";
    if (order == true)
    {
        for (int i = start_idx; i <= end_idx; ++i)
        {
            cout << v[i];
            if (i != end_idx)
                cout <<",";
        }
    }
    else
    {
        for (int i = end_idx; i >= start_idx; --i)
        {
            cout << v[i];
            if (i != start_idx)
                cout <<",";
        }
    }
    cout << "]" << endl;
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> tc;
    while (tc--)
    {
        cin >> func >> len;
        solve(func, len);
        memset(v, 0, sizeof(v));
    }
}
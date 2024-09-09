#include <iostream>
#include <stack>
#include <string>

using namespace std;

string str;
stack<char> s;

int main(void)
{
    cin >> str;
    int ret = 0;
    int tmp = 1;

    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == '(')
        {
            tmp *= 2;
            s.push(str[i]);
        }
        else if (str[i] == '[')
        {
            tmp *= 3;
            s.push(str[i]);
        }
        else if (str[i] == ')')
        {
            if (s.empty() || s.top() == '[')
            {
                ret = 0;
                break;
            }
            else if (str[i - 1] == '(')
                ret += tmp;
            tmp /= 2;
            s.pop();
        }
        else if (str[i] == ']')
        {
            if (s.empty() || s.top() == '(')
            {
                ret = 0;
                break;
            }
            else if (str[i - 1] == '[')
                ret += tmp;
            tmp /= 3;
            s.pop();
        }
    }
    if (!s.empty())
        cout << 0;
    else
        cout << ret;

    return (0);
}
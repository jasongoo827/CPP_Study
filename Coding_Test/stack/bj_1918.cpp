#include <iostream>
#include <stack>
#include <string>

using namespace std;

string str;
stack<char> s;

int check_operand(char c)
{
    if (c == '('||c == ')')
        return 1;
    else if (c == '+'||c == '-')
        return 2;
    else if (c == '*'||c == '/')
        return 3;
    else
        return 0;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> str;

    for (auto &c :str)
    {
        int op = check_operand(c);
        
        if (op == 0)
        {
            cout << c;
            continue;
        }
        else if (c == '(')
            s.push(c);
        else if (c == ')')
        {
            while (s.top() != '(')
            {
                cout << s.top();
                s.pop();
            }
            s.pop();
        }
        else
        {
            if (s.empty())
                s.push(c);
            else
            {
                while (!s.empty() && check_operand(s.top()) >= op)
                {
                    cout << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
    }
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }

    return (0);
}
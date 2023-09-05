#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str, explode;
stack<char> s;

int main(void)
{
    cin >> str >> explode;

    int exSize = explode.size();

    for (int i = 0; i < (int)str.size(); ++i)
    {
        s.push(str[i]);
        if (str[i] == explode[exSize - 1] && s.size() >= exSize)
        {
            string tmp = "";
            for (int j = 0; j < exSize; j++)
            {
                tmp += s.top();
                s.pop();
            }
            reverse(tmp.begin(), tmp.end());
            if (tmp != explode)
            {
                for (int j = 0; j < (int)tmp.size(); ++j)
                    s.push(tmp[j]);
            }
        }
    }
    
    if (s.empty()) cout << "FRULA";
    else
    {
        string ans = "";
        while (!s.empty())
        {
            ans += s.top();
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        cout << ans;
    }
}
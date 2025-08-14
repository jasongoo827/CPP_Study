#include <bits/stdc++.h>

using namespace std;

// 열린 괄호 바로 다음에 닫힌 괄호가 나오면 레이저.
// 바로 다음이 아니면 쇠막대기

string str;
stack<char> s;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;

    int ret = 0;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
        {
            s.push(str[i]);
        }
        else
        {
            if (s.top() == '(' && str[i - 1] == '(')
            {
                s.pop();
                ret += s.size();
            }
            else
            {
                s.pop();
                ret += 1;
            }
        }
    }

    cout << ret;

    return 0;
}
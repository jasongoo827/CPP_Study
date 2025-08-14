#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int n, k;
string input;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> input;
    
    stringstream ss(input);
    string part;
    bool first = true;
    int ret = 0;
    
    while (getline(ss, part, '-'))
    {
        int sum = 0;
        stringstream pss(part);
        string ps;
        
        while (getline(pss, ps, '+'))
            sum += stoi(ps);
        
        if (first)
        {
            ret += sum;
            first = false;
        }
        else
            ret -= sum;
    }
    cout << ret << '\n';
    
    return 0;
}
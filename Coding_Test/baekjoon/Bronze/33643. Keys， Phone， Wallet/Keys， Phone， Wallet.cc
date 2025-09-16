#include <iostream>
#include <set>

using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    set<string> bag;
    bag.insert("keys");
    bag.insert("phone");
    bag.insert("wallet");
    
    
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        if (bag.count(s))
            bag.erase(s);
    }
    
    if (bag.size() == 0)
    {
        cout << "ready\n";
        return 0;        
    }
    
    for (const auto& s: bag)
        cout << s << '\n';
    
    return 0;
}
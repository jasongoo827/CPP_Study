#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m;

string fizzbuzz(int n)
{
    if (n % 15 == 0) return "FizzBuzz";
    if (n % 3 == 0) return "Fizz";
    if (n % 5 == 0) return "Buzz";
    return to_string(n);
}

bool is_number(const string& s)
{
    for (char c : s)
        if (!isdigit(c)) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<string> input(3);
    for (int i = 0; i < 3; ++i)
        cin >> input[i];

    for (int i = 0; i < 3; ++i)
    {
        if (is_number(input[i]))
        {
            int num = stoi(input[i]);
            int start = num - i; 
            if (start <= 0)
                continue;

            if (fizzbuzz(start) == input[0] &&
                fizzbuzz(start + 1) == input[1] &&
                fizzbuzz(start + 2) == input[2])
            {
                cout << fizzbuzz(start + 3) << '\n';
                return 0;
            }
        }
    }
    
    return 0;
}

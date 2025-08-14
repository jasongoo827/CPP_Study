#include <iostream>
#include <string>
using namespace std;

int main() {
    string A, B, C;
    cin >> A >> B >> C;

    int a = stoi(A);
    int b = stoi(B);
    int c = stoi(C);
    cout << a + b - c << '\n';

    string concat = A + B;
    int result = stoi(concat) - stoi(C);
    cout << result << '\n';

    return 0;
}

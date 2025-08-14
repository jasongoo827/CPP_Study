#include <iostream>

using namespace std;

using Point = std::pair<int, int>;

struct Rect
{
    Point p1, p2;
};

void solve(Rect& r1, Rect r2)
{ 
    if ((r1.p2.first == r2.p1.first || r1.p1.first == r2.p2.first) &&
        (r1.p2.second == r2.p1.second || r1.p1.second == r2.p2.second))
    {
        cout << "c\n";
    }
    else if ((r1.p2.first == r2.p1.first || r1.p1.first == r2.p2.first) &&
             (r1.p1.second < r2.p2.second && r1.p2.second > r2.p1.second))
    {
        cout << "b\n";
    }
    else if ((r1.p2.second == r2.p1.second || r1.p1.second == r2.p2.second) &&
             (r1.p1.first < r2.p2.first && r1.p2.first > r2.p1.first))
    {
        cout << "b\n";
    }
    else if (r1.p2.first <= r2.p1.first || r1.p1.first >= r2.p2.first ||
             r1.p2.second <= r2.p1.second || r1.p1.second >= r2.p2.second)
    {
        cout << "d\n";
    }
    else
    {
        cout << "a\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 4;
    
    while (t--)
    {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        
        Rect r1{Point{x1, y1}, Point{x2, y2}};
        Rect r2{Point{x3, y3}, Point{x4, y4}};
        
        solve(r1, r2);
    }
    
    return 0;
}

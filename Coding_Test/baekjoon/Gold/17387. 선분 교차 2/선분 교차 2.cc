#include <iostream>

using namespace std;

struct Point
{
    int x;
    int y;
};

int ccw(Point& p1, Point& p2, Point& p3)
{
    long long cross = 1LL * (p2.x - p1.x) * (p3.y - p1.y) - 1LL * (p3.x - p1.x) * (p2.y - p1.y);
    
    if (cross > 0)
        return 1;
    else if (cross < 0)
        return -1;
    else
        return 0;
}

bool onSegment(const Point& p, const Point& q, const Point& r)
{
    return min(p.x, q.x) <= r.x && r.x <= max(p.x, q.x)
        && min(p.y, q.y) <= r.y && r.y <= max(p.y, q.y);
}

int main(int argc, const char * argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Point A, B, C, D;
    cin >> A.x >> A.y >> B.x >> B.y;
    cin >> C.x >> C.y >> D.x >> D.y;

    int r1 = ccw(A, B, C);
    int r2 = ccw(A, B, D);
    int r3 = ccw(C, D, A);
    int r4 = ccw(C, D, B);

    bool intersects = false;
    if (r1 * r2 < 0 && r3 * r4 < 0)
    {
        intersects = true;
    }
    else if ((r1 == 0 && onSegment(A, B, C))
          || (r2 == 0 && onSegment(A, B, D))
          || (r3 == 0 && onSegment(C, D, A))
          || (r4 == 0 && onSegment(C, D, B)))
    {
        intersects = true;
    }

    cout << (intersects ? 1 : 0) << "\n";
    
    return 0;
}

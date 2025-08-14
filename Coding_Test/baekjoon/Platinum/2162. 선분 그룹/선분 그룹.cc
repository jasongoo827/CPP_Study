#include <iostream>
#include <map>

using namespace std;

struct Point
{
    int x;
    int y;
};

struct Line
{
    Point p1;
    Point p2;
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

bool isIntersect(Line& l1, Line& l2)
{
    int r1 = ccw(l1.p1, l1.p2, l2.p1);
    int r2 = ccw(l1.p1, l1.p2, l2.p2);
    int r3 = ccw(l2.p1, l2.p2, l1.p1);
    int r4 = ccw(l2.p1, l2.p2, l1.p2);
    
    if (r1 * r2 < 0 && r3 * r4 < 0)
    {
        return true;
    }
    else if ((r1 == 0 && onSegment(l1.p1, l1.p2, l2.p1))
          || (r2 == 0 && onSegment(l1.p1, l1.p2, l2.p2))
          || (r3 == 0 && onSegment(l2.p1, l2.p2, l1.p1))
          || (r4 == 0 && onSegment(l2.p1, l2.p2, l1.p2)))
    {
        return true;
    }
    
    return false;
}

int n;
Line lines[3001];
int parent[3001];
int cnt[3001];

int get_parent(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = get_parent(parent[x]);
}

void union_parent(int a, int b)
{
    a = get_parent(a);
    b = get_parent(b);
    if (a > b)
        parent[a] = b;
    else
        parent[b] = a;
}

int main(int argc, const char * argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> lines[i].p1.x >> lines[i].p1.y >> lines[i].p2.x >> lines[i].p2.y;
    
    for (int i = 1; i <= n; ++i)
        parent[i] = i;
    
    for (int i = 1; i <= n - 1; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            if (isIntersect(lines[i], lines[j]))
            {
                union_parent(i, j);
            }
        }
    }
    
    for (int i = 1; i <= n; ++i)
    {
        int root = get_parent(i);
        cnt[root] += 1;
    }
    
    int group = 0;
    int maxSize = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (cnt[i] != 0)
            group++;
        if (maxSize < cnt[i])
            maxSize = cnt[i];
    }
    cout << group << '\n' << maxSize << '\n';

    return 0;
}

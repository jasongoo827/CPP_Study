#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point
{
	long long x, y;
};

int n;
vector<Point> points;
vector<Point> hull;

Point pivot;

long long crossProduct(Point& a, Point& b, Point& c)
{
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

long long distance(Point& a, Point& b)
{
	return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}

bool cmp(Point& a, Point& b)
{
	long long cp = crossProduct(pivot, a, b);
	if (cp == 0)
		return distance(pivot, a) < distance(pivot, b);
	return cp > 0;
}

void convexHull(vector<Point>& points)
{
	pivot = *min_element(points.begin(), points.end(), [](Point& a, Point& b) {
		return a.y == b.y ? a.x < b.x : a.y < b.y;
	});

	sort(points.begin(), points.end(), cmp);

	hull.push_back(points[0]);
	hull.push_back(points[1]);

	for (size_t i = 2; i < points.size(); ++i)
	{
		while (hull.size() >= 2 && crossProduct(hull[hull.size() - 2], hull.back(), points[i]) <= 0)
			hull.pop_back();
		hull.push_back(points[i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	points.assign(n, {0, 0});

	for (int i = 0; i < n; ++i)
		cin >> points[i].x >> points[i].y;
	
	convexHull(points);
	cout << hull.size();

	return 0;
}

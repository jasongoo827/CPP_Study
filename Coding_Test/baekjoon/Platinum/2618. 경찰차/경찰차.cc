#include <bits/stdc++.h>

using namespace std;

struct Pos
{
    int x;
    int y;
};

const int MAX = 1001;
int n, w, posX, posY;
int dp[MAX][MAX];
Pos event[MAX];

int dist(Pos A, Pos B)
{
    return abs(A.x - B.x) + abs(A.y - B.y);
}

int total_dist(int police1, int police2)
{
    if (police1 == w || police2 == w) return 0;

    if (dp[police1][police2] != -1) return dp[police1][police2];

    int nextEvent = max(police1, police2) + 1;
    int dist1, dist2;

    if (police1 == 0)
        dist1 = dist(Pos{ 1,1 }, event[nextEvent]);
    else
        dist1 = dist(event[police1], event[nextEvent]);

    if (police2 == 0)
        dist2 = dist(Pos{ n,n }, event[nextEvent]);
    else
        dist2 = dist(event[police2], event[nextEvent]);

    int res1 = dist1 + total_dist(nextEvent, police2);
    int res2 = dist2 + total_dist(police1, nextEvent);

    return dp[police1][police2] = min(res1, res2);
}

void printPoliceNum(int police1, int police2)
{
    if (police1 == w || police2 == w) return;

    int nextEvent = max(police1, police2) + 1;
    int dist1, dist2;

    if (police1 == 0)
        dist1 = dist(Pos{ 1,1 }, event[nextEvent]);
    else
        dist1 = dist(event[police1], event[nextEvent]);

    if (police2 == 0)
        dist2 = dist(Pos{ n,n }, event[nextEvent]);
    else
        dist2 = dist(event[police2], event[nextEvent]);

    if (dp[nextEvent][police2] + dist1 < dp[police1][nextEvent] + dist2)
    {
        cout << 1 << '\n';
        printPoliceNum(nextEvent, police2);
    }
    else
    {
        cout << 2 << '\n';
        printPoliceNum(police1, nextEvent);
    }
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> w;

    memset(dp, -1, sizeof(dp));

    for (int i = 1; i <= w; ++i)
    {
        cin >> posX >> posY;
        event[i].x = posX, event[i].y = posY;
    }

    cout << total_dist(0, 0) << '\n';
    printPoliceNum(0, 0);

    return 0;
}
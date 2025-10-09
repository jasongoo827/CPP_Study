#include <string>
#include <vector>

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    
    // dlru
    
    int diff = abs(r - x) + abs(c - y);
    if (k < diff || (k - diff) % 2)
        return "impossible";
    
    int remain = k;
    int curX = x, curY = y;
    
    while (remain > 0)
    {
        if (curX < n)
        {
            int newDist = abs(r - (curX + 1)) + abs(c - curY);
            if (newDist <= remain - 1)
            {
                curX++;
                remain--;
                answer += "d";
                continue;
            }
        }
        
        if (curY > 1)
        {
            int newDist = abs(r - curX) + abs(c - (curY - 1));
            if (newDist <= remain - 1)
            {
                curY--;
                remain--;
                answer += "l";
                continue;
            }
        }
        
        if (curY < m)
        {
            int newDist = abs(r - curX) + abs(c - (curY + 1));
            if (newDist <= remain - 1)
            {
                curY++;
                remain--;
                answer += "r";
                continue;
            }
        }
        
        if (curX > 1)
        {
            int newDist = abs(r - (curX - 1)) + abs(c - curY);
            if (newDist <= remain - 1)
            {
                curX--;
                remain--;
                answer += "u";
                continue;
            }
        }
    }
    
    return answer;
}
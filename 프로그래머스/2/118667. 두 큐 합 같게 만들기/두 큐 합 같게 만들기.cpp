#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    
    long long sum1 = 0, sum2 = 0;
    
    for (int n: queue1)
        sum1 += n;
    for (int n: queue2)
        sum2 += n;
    
    if ((sum1 + sum2) % 2)
        return -1;
    
    vector<int> combined;
    combined.insert(combined.end(), queue1.begin(), queue1.end());
    combined.insert(combined.end(), queue2.begin(), queue2.end());
    
    int l = 0, r = queue1.size();
    long long target = (sum1 + sum2) / 2;
    while (l < combined.size() && r < combined.size())
    {
        if (sum1 == target)
            return answer;
        if (sum1 > target && l < r)
        {
            sum1 -= combined[l];
            l++;
        }
        else if (sum1 < target)
        {
            sum1 += combined[r];
            r++;
        }
        else
            break;
        answer++;
    }
    
    return -1;
}
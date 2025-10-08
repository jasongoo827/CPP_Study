#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int deliver = 0;
    int pickup = 0;
    
    for (int i = n - 1; i >= 0; --i)
    {
        deliver += deliveries[i];
        pickup += pickups[i];
        
        while (deliver > 0 || pickup > 0)
        {
            deliver -= cap;
            pickup -= cap;
            
            answer += 2 * (i + 1);
        }
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <climits>
using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    // 모든 문제를 풀 수 있는 최소 능력치 찾기
    int max_alp_req = 0;
    int max_cop_req = 0;
    
    for (const auto& problem : problems) {
        max_alp_req = max(max_alp_req, problem[0]);
        max_cop_req = max(max_cop_req, problem[1]);
    }
    
    // 이미 모든 문제를 풀 수 있는 경우
    if (alp >= max_alp_req && cop >= max_cop_req)
        return 0;
    
    // 초기 능력치가 목표를 넘는 경우 조정
    alp = min(alp, max_alp_req);
    cop = min(cop, max_cop_req);
    
    // DP 배열 선언 (여유 공간 포함)
    const int MAX_SIZE = 151;  // 충분한 여유
    vector<vector<int>> dp(MAX_SIZE, vector<int>(MAX_SIZE, INT_MAX));
    
    // 초기 상태 설정
    dp[alp][cop] = 0;
    
    // Bottom-up DP
    for (int i = alp; i <= max_alp_req; ++i) {
        for (int j = cop; j <= max_cop_req; ++j) {
            if (dp[i][j] == INT_MAX) continue;  // 도달 불가능한 상태 스킵
            
            // 1. 알고력 공부 (1시간에 1 증가)
            if (i + 1 <= max_alp_req) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            }
            
            // 2. 코딩력 공부 (1시간에 1 증가)
            if (j + 1 <= max_cop_req) {
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
            }
            
            // 3. 문제 풀기
            for (const auto& problem : problems) {
                if (i >= problem[0] && j >= problem[1]) {
                    // 문제를 풀었을 때의 새로운 능력치
                    int new_alp = min(i + problem[2], max_alp_req);
                    int new_cop = min(j + problem[3], max_cop_req);
                    dp[new_alp][new_cop] = min(dp[new_alp][new_cop], 
                                               dp[i][j] + problem[4]);
                }
            }
        }
    }
    
    return dp[max_alp_req][max_cop_req];
}
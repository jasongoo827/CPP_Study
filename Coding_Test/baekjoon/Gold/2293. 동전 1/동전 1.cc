#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX = 100;
int n,k;

// 문제의 정의 = index에 따른 최대 길이

int dp[10001]={0,};
int coin[MAX];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>k;

    dp[0]=1;

    for(int i=0;i<n;++i)
        cin>>coin[i];

    for(int i=0;i<n;++i)
    {
        for(int j=coin[i];j<=k;++j)
        {
            dp[j]+=dp[j-coin[i]];
        }
    }

    cout<<dp[k];
    return 0;
}
#include <iostream>

using namespace std;

int n,s,m;
int vol[51];
int dp[51][1001]={0,};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>s>>m;

    for(int i=1;i<=n;i++)
        cin>>vol[i];

    dp[0][s]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(dp[i-1][j]==1)
            {
                if(j+vol[i]<=m) dp[i][j+vol[i]]=1;
                if(j-vol[i]>=0) dp[i][j-vol[i]]=1;
            }
        }
    }

    for(int i=m;i>=0;i--)
    {
        if(dp[n][i])
        {
            cout<<i;
            return 0;
        }
    }

    cout<<"-1";

    return 0;
}

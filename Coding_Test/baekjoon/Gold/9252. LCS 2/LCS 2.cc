#include <bits/stdc++.h>

using namespace std;

const int MAX = 1001;

string str1, str2, res;
int dp[MAX][MAX]={0,};

//0 0 0 0 0 0 0
//0 0 1 1 1 1 1
//0 1 1 1 2 2 2
//0 1 2 2 2 3 3
//0 1 2 2 2 3 3
//0 1 2 2 2 3 4
//0 1 2 3 3 3 4

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>str1>>str2;

    for(int i=0;i<(int)str1.size();++i)
    {
        for(int j=0;j<(int)str2.size();++j)
        {
            if(str1[i]==str2[j])
                dp[i+1][j+1]=dp[i][j]+1;
            else
                dp[i+1][j+1]= max(dp[i+1][j], dp[i][j+1]);
        }
    }

    int col = str1.size();
    int row = str2.size();

    while(dp[col][row])
    {
        if(dp[col][row]==dp[col-1][row])
            col--;
        else if(dp[col][row]==dp[col][row-1])
            row--;
        else
        {
            res.push_back(str1[col-1]);
            col--, row--;
        }
    }

    cout<<dp[str1.size()][str2.size()]<<'\n';
    
    if(dp[str1.size()][str2.size()]!=0)
    {
        reverse(res.begin(), res.end());
        cout<<res;
    }

    return 0;
}
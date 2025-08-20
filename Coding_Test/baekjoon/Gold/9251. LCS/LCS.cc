#include <iostream>
#include <string>

using namespace std;

const int MAX = 1001;

string str1, str2;
int dp[MAX][MAX]={0,};


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>str1>>str2;

    int start=0;

    int size1 = str1.length();
    int size2 = str2.length();

    for(int i=0;i<size1;++i)
    {
        for(int j=0;j<size2;++j)
        {
            if(str1[i]==str2[j])
                dp[i+1][j+1]=dp[i][j]+1;
            else
                dp[i+1][j+1]= max(dp[i+1][j], dp[i][j+1]);
        }
    }

    cout<<dp[size1][size2];
    return 0;
}
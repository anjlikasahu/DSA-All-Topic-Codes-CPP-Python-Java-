
#include<iostream>
#include<vector>
using namespace std;

int rodcutting(vector<int> wt, vector<int> val, int cap)
{
    int n = wt.size();
    vector<vector<int>> dp(n+1, vector<int>(cap+1, 0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=cap;j++)
        {
            if(wt[i-1]<=j)
            dp[i][j] =  max((val[i-1]+dp[i][j-wt[i-1]]) , dp[i-1][j]);
        else
            dp[i][j] = dp[i-1][j];
        }

    }
        return dp[n][cap];
}

int main()
{

    cout<<rodcutting({1,2,3,4,5,6,7,8},{1,5,8,9,10,17,17,20},8);

    return 0;

}


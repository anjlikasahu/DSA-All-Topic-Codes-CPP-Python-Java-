#include<iostream>
#include<vector>
using namespace std;

int coinchange(vector<int> coins, int cap)
{
    int n = coins.size();
    vector<vector<int>> dp(n+1, vector<int>(cap+1, 0));
    for(int i=0;i<=n;i++)
    {
        dp[i][0] = 1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=cap;j++)
        {
            if(coins[i-1]<=j)
            dp[i][j] =  dp[i][j-coins[i-1]] + dp[i-1][j];
        else
            dp[i][j] = dp[i-1][j];
        }

    }
        return dp[n][cap];
}

int main()
{

    cout<<coinchange({1,2,3},5);

    return 0;

}



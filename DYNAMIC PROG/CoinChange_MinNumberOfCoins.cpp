#include<iostream>
#include<vector>
using namespace std;

int coinchange(vector<int> coins, int cap)
{
    int n = coins.size();
    vector<vector<int>> dp(n+1, vector<int>(cap+1, 0));
    for(int i=0;i<=cap;i++)
    {
        dp[0][i] = INT_MAX-1;
    }
    for(int j=1;j<=cap;j++)
    {
        if(j%coins[0] == 0)
        {

            dp[1][j] = j/coins[0];
        }
        else
        {

            dp[1][j] = INT_MAX-1;
        }
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=cap;j++)
        {
            if(coins[i-1]<=j)
            dp[i][j] =  min(1+dp[i][j-coins[i-1]] , dp[i-1][j]);
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




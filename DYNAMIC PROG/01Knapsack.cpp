#include<iostream>
#include<vector>
using namespace std;
int unboundedknapsack(vector<int> wt, vector<int> val, int cap)
{
    int n = wt.size();
    vector<vector<int>> dp(n+1, vector<int>(cap+1, 0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=cap;j++)
        {
            if(wt[i-1]<=j)
            dp[i][j] =  max((val[i-1]+dp[i-1][j-wt[i-1]]) , dp[i-1][j]);
        else
            dp[i][j] = dp[i-1][j];
        }

    }
        return dp[n][cap];
}

int main()
{

    cout<<unboundedknapsack({4,5,1},{1,2,3},4)<<endl;
    cout<<unboundedknapsack({4,5,6},{1,2,3},3);
    return 0;

}

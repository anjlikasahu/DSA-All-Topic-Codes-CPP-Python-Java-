
#include<iostream>
#include<vector>
using namespace std;
int subsetsum(vector<int> arr, int sum)
{
    int n = arr.size();
    vector<vector<bool>>dp(arr.size()+1,vector<bool>(sum+1,false));

  for(int i=0;i<arr.size()+1;i++){
        dp[i][0]=true;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1]<=j)
            dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
        else
            dp[i][j] = dp[i-1][j];
        }

    }
        return dp[n][sum];
}
}

int main(){
    cout<<subsetsum({3, 34, 4, 12, 5, 2},9);
}

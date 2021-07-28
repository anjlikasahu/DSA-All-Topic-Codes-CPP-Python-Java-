#include<bits/stdc++.h>
using namespace std;

int minjumps(vector<int>arr)
{
    vector<int>dp(arr.size(), INT32_MAX);
    dp[0]=0;
    for(int i=1;i<arr.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]+j >= i && dp[j]!=INT32_MAX)
            {
                dp[i] = min(dp[i],dp[j]+1);
                break;
            }
        }
    }
    return dp[arr.size()-1];
}

int main()
{
    vector<int>arr={2,3,1,1,2,4,2,0,1,1};
    cout<<minjumps(arr);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int countbst(int n)
{
    vector<int>dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            dp[i] = dp[i]+(dp[j-1] * dp[i-j]); //left subtree count = i-1 and right subtree count = n-i;
        }
    }
    return dp[n];
}

int main()
{
    int n =5;
    cout<<countbst(n);
    return 0;
}

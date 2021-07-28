#include<bits/stdc++.h>
using namespace std;

bool ispalin(string s, int a, int b)
{
    while(a<b)
    {
        if(s[a]!=s[b])
            return false;
        a++; b--;
    }
    return true;
}

int palinpart(string s, int i, int j)
{
    //OPTIMISED CODE:

    int n = s.size();
    vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
    if(i>=j) return 0;
    int left, right;
    if(ispalin(s,i,j)) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int m = INT_MAX;
    for(int k=i;k<j;k++)
    {
        left=0; right=0;
        if(dp[i][k]!=-1)
            left=dp[i][k];
        else
            left=palinpart(s,i,k);

         if(dp[k+1][j]!=-1)
            right=dp[k+1][j];
        else
            right=palinpart(s,k+1,j);

        int t = left +1 + right;
        m=min(t,m);
    }
    return dp[i][j]=m;
}

int main()
{
    string s= "nitik";
    cout<<palinpart(s,0, s.size()-1);
    return 0;
}

/* NON OPTIMISED CODE:
int n = s.size();
    vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
    if(i>j) return 0;
    if(ispalin(s,i,j)) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int m = INT_MAX;
    for(int k=i;k<j;k++)
    {
        int t = palinpart(s,i,k) +1 + palinpart(s,k+1,j);
        m=min(t,m);
    }
    return dp[i][j]=m; */


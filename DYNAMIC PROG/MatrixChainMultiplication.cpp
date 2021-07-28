#include<bits/stdc++.h>
using namespace std;

int mcm(vector<int> a, int i, int j)
{
    int n = a.size();
    vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
    if(i>=j) return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int res=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int t = mcm(a,i,k)+mcm(a,k+1,j)+(a[i-1]*a[k]*a[j]);
        res=min(res,t);
    }
    return dp[i][j]=res;
}

int main()
{
    vector<int>v ={50,20,1,10,100};
    cout<<mcm(v,1,v.size()-1);
    return 0;
}

/*RECURSIVE CODE:
if(i>=j) return 0;
    int res=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int t = mcm(a,i,k)+mcm(a,k+1,j)+(a[i-1]*a[k]*a[j]);
        res=min(res,t);
    }
    return res;*/

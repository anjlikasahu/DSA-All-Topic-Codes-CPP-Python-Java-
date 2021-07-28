#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int lcs(string a, string b)
{
    int m = a.size();
    int n = b.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for(int i=1;i<=m;i++) {
        for(int j=1;j<=n;j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1+dp[i-1][j-1]; }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    return dp[m][n];
}

int main()
{
    cout<<lcs("anjlika", "samik");
}

#include<iostream>
#include<vector>

using namespace std;

int lcstr(string a, string b)
{
    int m = a.size();
    int n = b.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for(int i=1;i<=m;i++) {
        for(int j=1;j<=n;j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1+dp[i-1][j-1]; }
            else{
                dp[i][j]= 0;
            }
        }
    }

    int res=INT32_MIN;
    for(int i=0;i<a.size()+1;i++){
        for(int j=0;j<b.size()+1;j++){
           res=max(dp[i][j],res);
        }
    }
    return res;
}

int main()
{
    cout<<lcstr("anjlika", "samik");
}

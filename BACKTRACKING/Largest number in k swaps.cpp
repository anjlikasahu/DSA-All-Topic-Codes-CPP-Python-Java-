#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       
        if (k == 0)
        return str;
        string ans = "";
        findmax(str, ans, k, str.size(), 0);
        return ans;
       
    }
    void findmax(string str, string &ans, int k, int n, int i) {
if (k == 0)
return ;
char maxs = str[i];
for (int j = i + 1; j < n; j++) {
maxs = max(maxs, str[j]);
}
if (maxs != str[i])
k--;
for (int j = i; j < n; j++) {
if (str[j] == maxs) {
swap(str[i], str[j]);
ans = max(ans, str);
findmax(str, ans, k, n, i + 1);
swap(str[i], str[j]);
}
}
return;
}
    
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends
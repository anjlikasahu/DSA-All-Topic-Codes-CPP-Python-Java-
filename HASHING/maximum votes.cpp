#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        vector<string> ans;
        map<string, int> m;
        int count=-1;
        string res;
        for(int i=0;i<n;i++)
        {
            m[arr[i]]++;
            if(count<m[arr[i]])
            {
                count = m[arr[i]];
                res = arr[i];
            }
            if(count == m[arr[i]])
            {
                res = min(res, arr[i]);
            }
            
        }
        ans.push_back(res);
        ans.push_back(to_string(count));
        return ans;
        
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}
  // } Driver Code Ends
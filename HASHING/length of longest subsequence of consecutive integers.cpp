// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      int res=1;
      map<int, int>m;
      int ans=1;
      for(int i=0;i<n;i++)
      {
          m[arr[i]]++;
      }
      vector<pair<int, int>>v;
      for(auto x:m)
      {
          v.push_back(make_pair(x.first, x.second));
      }
      for(int i=0;i<v.size();i++)
      {
          if(i>0 && v[i].first == v[i-1].first + 1)
          {
              res++;
              ans = max(res, ans);
          }
          else
          {
              res=1;
          }
      }
      return ans;
      
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends
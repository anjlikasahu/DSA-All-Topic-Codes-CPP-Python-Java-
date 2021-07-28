#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        //Your code here
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
            {
                arr[i]= -1;
            }
        }
        unordered_map<int, int> m;
        int ps=0;
        for(int i=0;i<n;i++)
        {
            ps+=arr[i];
            m[ps]++;
        }
        int res=0;
        for(auto x:m)
        {
            int c = x.second;
            res += (c*(c-1))/2;
                
            if(x.first == 0)
            {
                res+=x.second;
            }
            
            
        }
        return res;
        
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution obj;
	cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}
  // } Driver Code Ends
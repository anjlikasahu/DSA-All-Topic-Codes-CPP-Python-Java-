#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    //Function to count the number of subarrays which adds to the given sum.
    int subArraySum(int arr[], int n, int s)
    {
        //Your code here
        unordered_map<int, int> m;
        m[0]=1;
        int sum = 0;
        int res=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            int rem = sum - s;
            if(m.find(rem) != m.end())
            {
                res+=m[rem];
            }
            m[sum]++;
            
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
	    int n,sum=0;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    cin>>sum;
	    Solution obj;
	    cout<<obj.subArraySum(arr, n, sum)<<endl;
	}
	return 0;
}  // } Driver Code Ends
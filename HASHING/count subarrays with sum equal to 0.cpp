//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        //code here
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
        int n;
        cin>>n; //input size of array
       
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}  // } Driver Code Ends
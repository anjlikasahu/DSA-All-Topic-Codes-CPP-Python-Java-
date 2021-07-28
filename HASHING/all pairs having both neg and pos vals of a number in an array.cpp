// Initial function template for C++

#include <bits/stdc++.h>
#include <unordered_map>
#include <math.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
  public:
    //Function to return list containing all the pairs having both
    //negative and positive values of a number in the array.
    vector <int> findPairs(int arr[], int n) 
    {
        // code here
        int t;
        vector<int> res;
        unordered_set<int> s;
        for(int i=0;i<n;i++)
        {
            t = (-1)*arr[i];
            if(s.find(t) == s.end())
            {
                s.insert(arr[i]);
            }
            else
            {
                if(t<arr[i])
                {
                    res.push_back(t);
                    res.push_back(arr[i]);
                }
                if(t>arr[i])
                {
                    res.push_back(arr[i]);
                    res.push_back(t);
                }
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        vector <int> res = obj.findPairs(arr, n);
    	if(res.size()!=0)
    	{
    		for (int i : res) 
            	cout << i << " ";
        	cout << endl;	
    	}
    	else
    		cout<<0<<endl;
    }

    return 0;
}  // } Driver Code Ends
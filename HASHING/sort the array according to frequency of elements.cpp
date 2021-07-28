#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

bool sortbyval(const pair<int, int> &a, const pair<int, int> &b)
    {
        if(a.second != b.second)
        {
            return a.second > b.second;
        }
        else
        {
            return a.first < b.first;
        }
        
    }
class Solution{
    public:
    //Complete this function
    //Function to sort the array according to frequency of elements.
    
    
    vector<int> sortByFreq(int arr[],int n)
    {
        //Your code here
        unordered_map<int, int> m;
        for(int i=0;i<n;i++)
        {
            m[arr[i]]++;
        }
        vector<pair<int, int>>v;
        for(auto x:m)
        {
            v.push_back(make_pair(x.first, x.second));
        }
        
        sort(v.begin(), v.end(), sortbyval);
        
       vector<int> res;
       
       for(int i=0;i<v.size();i++)
       {
           int temp = v[i].second;
           while(temp--)
           {
               res.push_back(v[i].first);
           }
       }
       return res;
    }
};

// { Driver Code Starts.

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution obj;
	    vector<int> v;
	    v = obj.sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}

  // } Driver Code Ends
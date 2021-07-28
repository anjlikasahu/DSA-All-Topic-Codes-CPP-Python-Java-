#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
// Function to print the k numbers with most occurrences 
bool sortbv(const pair<int, int> &a, 
               const pair<int, int> &b) 
{ 
    return (a.second > b.second); 
} 

class Solution
{
    public:
    //Function to return the sum of frequencies of k numbers
    //with most occurrences in an array.
    int kMostFrequent(int arr[], int n, int k) 
    { 
    	// Your code here
    	map<int, int>m;
    	vector<pair<int,int>>v;
    	for(int i=0;i<n;i++)
    	{
    	    m[arr[i]]++;
    	}
    	for(auto x :m)
    	{
    	   v.push_back(make_pair(x.first, x.second));
    	}
    	sort(v.begin(), v.end(), sortbv);
    	int sum=0;
    	for (int i = 0; i < k; i++)
    	{
    	    sum+=v[i].second;
    	}
    	return sum;
    	
    } 
};

// { Driver Code Starts.
// Driver program to test above 
int main() 
{
	int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.kMostFrequent(arr, n, k) << endl; 
    }

	return 0; 
} 
  // } Driver Code Ends
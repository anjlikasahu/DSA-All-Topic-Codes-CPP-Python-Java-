// { Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find repeated element and its frequency.
    pair<int, int> findRepeating(int *arr, int n){
        //code here
        pair<int, int>p;
        unordered_map<int, int> m;
        int low=0;
        int high=n-1;
        int temp;
       while(low<=high)
       {
           m[arr[low]]++;
           m[arr[high]]++;
           if(m[arr[low]]>1)
           {
               temp=arr[low];
               break;
           }
           if(m[arr[high]]>1)
           {
               temp=arr[high];
               break;
           }
           low++; high--;
       }
       int c;
       c = count(arr, arr+n, temp);
       p.first = temp;
       p.second = c;
       return p;
       
       
    }
};

// { Driver Code Starts.

int main() {
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        pair<int, int> ans = obj.findRepeating(arr,n);
        
        cout << ans.first << " " << ans.second << endl;
        
    }
    
}  // } Driver Code Ends
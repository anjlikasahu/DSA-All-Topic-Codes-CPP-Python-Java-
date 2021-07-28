// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x){
        
        int i=0; 
        int j=n-1;
        int mid; 
        if(x<v[0])
        return -1;
        int temp=0;
        int res=INT_MAX;
        
        while(i<=j)
        {
            mid=(i+j)/2;
            if(v[mid]==x)
            return mid;
            if(x<v[mid])
            {
                j=mid-1;
                temp=v[mid]-x;
                res=min(temp, res);
            }
            if(x>v[mid])
            {
                i=mid+1;
                temp=x-v[mid];
                res=min(temp,res);
            }
        }
        return mid;
        
    }
};


// { Driver Code Starts.

int main() {
    
    long long t;
    cin >> t;
    
    while(t--){
        long long n;
        cin >> n;
        long long x;
        cin >> x;
        
        vector<long long> v;
        
        for(long long i = 0;i<n;i++){
            long long temp;
            cin >> temp;
            v.push_back(temp);
        }
        Solution obj;
        cout << obj.findFloor(v, n, x) << endl;
       
    }
    
    return 0;
}  // } Driver Code Ends
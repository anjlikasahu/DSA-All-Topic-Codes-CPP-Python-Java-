#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long, vector<long long>, greater<long long>>pq(arr, arr+n);
        
        long long cost=0;
        if(n==1)
        {
            return 0;
        }
        if(n==2)
        {
            return arr[0]+arr[1];
        }

        while(pq.size()!=1)
        {
            long long a1 = pq.top();
            pq.pop();
            long long a2 = pq.top();
            pq.pop();
            
            cost += a1+a2;
            pq.push(a1+a2);
            
        }
        
        
        return cost;
        
    }
};


// { Driver Code Starts.
long long minCost(long long arr[], long long n);
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
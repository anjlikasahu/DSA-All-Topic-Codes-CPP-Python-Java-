// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to find maximum number of consecutive steps 
    //to gain an increase in altitude with each step.
    int maxStep(int A[], int N)
    {
        int count = 0;
        int max_count = 0;
        for(int i = 0; i < N-1; ++i)
        {
        if(A[i] < A[i+1])
        {
        count++;
        if(i == N-2)
        {
        max_count = max(max_count, count);
        } 
            
        }
        else
        {
        max_count = max(max_count, count);
        count = 0;
        }
        }
        return max_count;
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int a[n];
        
        for(int i=0;i<n;i++)
        cin>>a[i];
        Solution ob;
        cout << ob.maxStep(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends
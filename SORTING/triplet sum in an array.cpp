// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        sort(A, A+n);
        int l=0;
        int sum=0;
        int h=0;
        for(int i=0;i<n-2;i++)
        {
            l=i+1;
            h=n-1;
            while(l<h)
            {
                sum=A[i]+A[h]+A[l];
                if(sum==X)
                {
                    return true;
                }
                if(sum>X)
                {
                    h--;
                }
                if(sum<X)
                {
                    l++;
                }
            }
            
        }
        return false;
    }

};

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,X;
        cin>>n>>X;
        int i,A[n];
        for(i=0;i<n;i++)
            cin>>A[i];
        Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends
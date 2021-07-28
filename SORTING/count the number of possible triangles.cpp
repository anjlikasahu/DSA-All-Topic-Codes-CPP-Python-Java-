#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int arr[], int n)
    {
        // code here
        int l; int h;
        int i;
        int cnt = 0;
        
        sort(arr, arr+n);
        
        for(i=n-1;i>=1;i--)
        {
            l=0;
            h=i-1;
            while(l<h)
            {
                if(arr[l]+arr[h]>arr[i])
                {
                    cnt+= h-l;
                    h--;
                }
                else{
                    l++;
                }
            }
        }
        return cnt;
    }
};


// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.findNumberOfTriangles(arr,n) <<endl;
    }
    return 0;
}  // } Driver Code Ends.

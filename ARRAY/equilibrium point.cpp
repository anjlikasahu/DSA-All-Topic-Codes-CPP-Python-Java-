// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int abc(long long a[], int start, int end)
    {
        int sum=0;
        for(int i=start;i<=end;i++)
        {
            sum+=a[i];
        }
        return sum;
    }
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        int x,y;
        int t=-1;
        int len = sizeof(a)/sizeof(a[0]);
        if(len<4)
        {
            return a[0];
        }
        for(int i=1;i<n-1;i++)
        {
           x=abc(a,0,i-1);
           y=abc(a,i+1,n-1);
           if(x==y)
           {
               t=i+1;
               break;
           }
        }
        return t;
        
    }

};

// { Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
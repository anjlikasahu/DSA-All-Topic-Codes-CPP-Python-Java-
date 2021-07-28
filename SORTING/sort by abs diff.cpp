#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

bool compareInterval(int X,int Y)
        {
            return (abs(X)<abs(Y));
        }
class Solution{
    public:
    int j;
    
    // A[]: input array
    // N: size of array
    //Function to sort the array according to difference with given number.
    
        
           
    void sortABS(int A[],int N, int k)
        {
           //Your code here
           for(int i=0;i<N;i++)
           {
               A[i]-=k;
           }
           
           stable_sort(A,A+N,compareInterval);
           for(int i=0;i<N;i++)
           {
               A[i]+=k;
           }
        }
                

};

// { Driver Code Starts.

int main()
 {
    int T;
    cin>> T;
    
    while (T--)
    {
        
        int N, diff;
        cin>>N>>diff;
        int A[N];
        
        for(int i = 0; i<N; i++)
            cin>>A[i];
       
        Solution ob;
       
        ob.sortABS(A, N, diff);
        
        for(int & val : A)
            cout<<val<<" ";
        cout<<endl;
        
    }
    
    return 0;
}  // } Driver Code Ends
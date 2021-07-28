#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    
    // The function should do the stated modifications in the given array arr[]
    // Do not return anything.
    
    // arr[]: Input Array
    // N: Size of the Array arr[]
    //Function to segregate 0s, 1s and 2s in sorted increasing order.
    void segragate012(int arr[], int N)
    {
        // Your Code Here
        vector<int>res1;
        vector<int>res2;
        vector<int>res3;
        int k=0;
        
        for(int i=0;i<N;i++)
        {
            if(arr[i]==0) res1.push_back(arr[i]);
            if(arr[i]==1) res2.push_back(arr[i]);
            if(arr[i]==2) res3.push_back(arr[i]);
        }
        
        vector<int>v(res1);
        v.insert(v.end(), res2.begin(), res2.end());
        v.insert(v.end(), res3.begin(), res3.end());
        for (auto l: v)
        {
            arr[k]=l;
            k++;
        }
        
        
    }
};

// { Driver Code Starts.
int main() {

    int T;
    cin >> T;

    while(T--){
        int N;
        cin >>N;
        int A[N];
        for(int i=0;i<N;i++){
            cin >> A[i];
        }

        Solution ob;
        ob.segragate012(A, N);

        for(int i=0;i<N;i++){
            cout << A[i]  << " ";
        }

        cout << endl;
        
        
    }

}
  // } Driver Code Ends
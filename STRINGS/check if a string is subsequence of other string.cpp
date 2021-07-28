
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to check if a string is subsequence of other string.
    bool isSubSequence(string A, string B)
    {
        //code here
        int i=0;
        int j=0;
        int cnt =0 ;
        int n=A.length();
        int m=B.length();
        if(n>m)
        {
            return false;
        }
        while(i<n && j<m)
        {
            if(A[i] == B[j])
            {
                i++;
                j++;
                cnt++;
            }
         
            else
            {
                j++;
            }
        }
        if(cnt == n)
        {
            return true;
        }
        return false;
        
    }
};

// { Driver Code Starts.
    
int main() {
	
	int t;
	cin>>t;
	while(t--){
	    string A, B; cin>>A>>B;
	    Solution ob;
	    bool ans = ob.isSubSequence(A, B);
	    if(ans)
	        cout<<"True"<<endl;
	    else
	        cout<<"False"<<endl;
	}
	return 0;
}  // } Driver Code Ends
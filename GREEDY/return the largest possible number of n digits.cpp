#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return Largest Number

class Solution
{
    public:
    //Function to return the largest possible number of n digits
    //with sum equal to given sum.
    string largestNumber(int n, int sum)
    {
        // Your code here
        
        string output(n, '0');
    
    for(int i = 0; i < n; i++)
    {
        int val = 0;
        if(sum > 9)
        {
            val = 9;
            sum -= 9;
        }
        else
        {
            val = sum;
            sum = 0;
        }
        
        output[i] = val + '0';
    }
    
    if(sum > 0)
    {
        return "-1";
    }
    
    return output;
    }
};

// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin>>t;

	while(t--)
	{
	    //taking n and sum
		int n,sum;
		cin>>n>>sum;
		
        Solution obj;
        //function call
		cout<<obj.largestNumber(n, sum)<<endl;
	}
	return 0;
}  // } Driver Code Ends
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
        
        if(str1.size() != str2.size())
        {
            return false;
        }
        
        int n = str1.size();
        
        if(n == 1)
        {
            if(str1[0] == str2[0])
            {
                return true;
            }
            return false;
        }
        
        if(str1[0] == str2[n - 2] and str1[1] == str2[n - 1])
        {
            return true;
        }
        
        if(str2[0] == str1[n - 2] and str2[1] == str1[n - 1])
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
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}
  // } Driver Code Ends
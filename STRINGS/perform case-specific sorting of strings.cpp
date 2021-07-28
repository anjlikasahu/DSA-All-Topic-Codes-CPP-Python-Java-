// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        vector<char> upper;
        vector<char> lower;
        
        string res="";
        
        for(int i=0;i<n;i++)
        {
            if (islower(str[i]))
            {
                lower.push_back(str[i]);
            }
            if (isupper(str[i]))
            {
                upper.push_back(str[i]);
            }
        }
        sort(lower.begin(), lower.end());
        sort(upper.begin(), upper.end());
        int k=0;
        int l=0;
        for(int i=0;i<n;i++)
        {
            if (isupper(str[i]))
            {
                res=res+upper[k];
                k++;
            }
            if (islower(str[i]))
            {
                res=res+lower[l];
                l++;
            }
        }
        if(l+k == n-2)
        {
            return res;
        }
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}  // } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to remove pair of duplicates from given string using Stack.
    string removePair(string s)
    {
        // Your code here
       stack<char>st;
        string res="";
        st.push(s[0]);
        for(int i=1;i<s.length();i++)
        {
            if(!st.empty() && s[i]==st.top())
            {
                st.pop();
                continue;
            }
            else
            {
                st.push(s[i]);
            }
        }
        while(!st.empty())
        {
            res=st.top()+res;
            st.pop();
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        string s;
        cin>>s;
        Solution obj;
        string ans = obj.removePair (s);
        if(ans=="")
            cout<<"Empty String"<<endl;
        else
            cout<<ans<<endl;
    }
    
	return 0;
}  // } Driver Code Ends
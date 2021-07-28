#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    
    bool ispar(string x)
    {
        // Your code here
        stack<char> s;
        for(int i=0;i<x.length();i++)
        {
            if(x[i]=='{' || x[i]=='[' || x[i]=='(')
            {
                s.push(x[i]);
            }
            else if(x[i]==')')
            {
                if(s.empty()==false && s.top()=='(')
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
             else if(x[i]=='}')
            {
                if(s.empty()==false && s.top()=='{')
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
             else if(x[i]==']')
            {
                if(s.empty()==false && s.top()=='[')
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if(s.empty() == true)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends
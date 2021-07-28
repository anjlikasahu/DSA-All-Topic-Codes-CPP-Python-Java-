// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string &str)
    {
        int n=str.length();
        int count[26] = {0};
        
        for(int i=0;i<n;i++)
        {
            str[i] = tolower(str[i]);
            if(str[i]>='a' && str[i]<='z')
            {
                count[str[i] - 'a']++;
            }
        }
        
        for(int i=0;i<26;i++)
        {
            if(count[i]==0)
            {
                return false;
            }
        }
        
        return true;
        
    }

};

// { Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string str;
        getline(cin, str);
        Solution obj;
        if (obj.checkPangram(str) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}
  // } Driver Code Ends
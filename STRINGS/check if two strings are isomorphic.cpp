// { Driver Code Starts
// C++ program to check if two strings are isomorphic
#include<iostream>
#include<string.h>

using namespace std;
#define MAX_CHARS 256

 // } Driver Code Ends



class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        if(str1.length()!=str2.length())
        {
            return false;
        }
        int hash1[26]={0};
        int hash2[26]={0};
        for(int i=0;i<str1.length();i++)
        {
            hash1[str1[i] - 'a']++;
            hash2[str2[i] - 'a']++;
            
            if(hash1[str1[i] - 'a'] != hash2[str2[i] - 'a'])
            {
                return false;
            }
            
        }
        return true;
        
        
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}  // } Driver Code Ends
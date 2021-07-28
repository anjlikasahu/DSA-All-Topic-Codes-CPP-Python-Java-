// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        // Your code here
        int alen = a.length();
    int blen = b.length();
    if(alen != blen)
    {
        return false;
    }
    
    int count1[256] = {0};
    for(int i=0;i<alen;i++)
    {
        count1[a[i]]++;
        count1[b[i]]--;
    }
    for(int i=0;i<256;i++)
    {
        if(count1[i]!=0)
        {
            return false;
        }
    }
    return true;
        
    }

};

// { Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}
  // } Driver Code Ends
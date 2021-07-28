//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

string printNumber(string , int);

// User function pasted here
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s,temp;
		cin>>s;
		int i,len=s.length();
		
		cout << printNumber(s,len) << "\n";
	}
	return 0;
}// } Driver Code Ends


//User function template for C++


//Function to find matching decimal representation of a string as on the keypad.
string printNumber(string s, int n) 
{
    //code here
    string res = "";
    for(int i=0;i<n;i++)
    {
        if(s[i]>='a' && s[i]<='c')
        {
            res+='2';
        }
        if(s[i]>='d' && s[i]<='f')
        {
            res+='3';
        }
        if(s[i]>='g' && s[i]<='i')
        {
            res+='4';
        }
        if(s[i]>='j' && s[i]<='l')
        {
            res+='5';
        }
        if(s[i]>='m' && s[i]<='o')
        {
            res+='6';
        }
        if(s[i]>='p' && s[i]<='s')
        {
            res+='7';
        }
        if(s[i]>='t' && s[i]<='v')
        {
            res+='8';
        }
        if(s[i]>='w' && s[i]<='z')
        {
            res+='9';
        }
    }
    return res;
}

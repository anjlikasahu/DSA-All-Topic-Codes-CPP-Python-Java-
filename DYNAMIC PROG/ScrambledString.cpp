#include<bits/stdc++.h>
using namespace std;

bool solve(string s1, string s2)
{
    unordered_map<string, bool>mp;
    string s=s1;
    s.append("__");
    s.append(s2);
    if(mp.find(s1)!=mp.end())
        return mp[s1];

    if(s1.compare(s2)==0) return true;
    if(s1.size()<=1) return false;
    int n = s1.length();
    bool flag = false;
    for(int i=1;i<n;i++)
    {
        bool swapyes = solve(s1.substr(0,i), s2.substr(n-i,i)) && solve(s1.substr(i,n-i), s2.substr(0,n-i));
        bool swapno =  solve(s1.substr(0,i), s2.substr(0,i)) && solve(s1.substr(i,n-i), s2.substr(i,n-i));
        if(swapyes || swapno)
           {
               flag=true;
                break;
           }
    }
    return mp[s1]=flag;

}
int main()
{
    string s1="great";
    string s2="eatgr";
    cout<<solve(s1,s2);

}

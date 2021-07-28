#include<bits/stdc++.h>
using namespace std;

int editdist(string a, string b)
{
    int row=b.size();
    int col=a.size();
    vector<vector<int>>t(row+1, vector<int>(col+1,0));
    for(int i=0;i<=row;i++)
    {
        for(int j=0;j<=col;j++)
        {
            if(i==0)
                t[i][j]=j;
            if(j==0)
                t[i][j]=i;
        }
    }

    for(int i=1;i<row+1;i++)
    {
        for(int j=0;j<col+1;j++)
        {
            if(a[j-1] == b[i-1])
                t[i][j] = t[i-1][j-1];
            else
                t[i][j] = 1+ min(min(t[i-1][j-1], t[i-1][j]), t[i][j-1]);
        }
    }
    return t[row][col];
}

int main()
{
    string a="horse";
    string b="ros";
    cout<<editdist(a,b);
    return 0;
}

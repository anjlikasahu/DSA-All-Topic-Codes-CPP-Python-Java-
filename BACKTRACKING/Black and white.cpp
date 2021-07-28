#include <bits/stdc++.h>

using namespace std;

long long solve(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << solve(n, m) << endl;
    }
    return 0;
}// } Driver Code Ends





//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
long long solve(int n, int m)
{
    // write code here
    int c=1;
    long long res = 0 ;
    int tot = n*m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i-1>=0 && j+2<m)
            c++;
            if(i+1<n && j+2<m)
            c++;
            if(i+2<n && j+1<m)
            c++;
            if(i+2<n && j-1>=0)
            c++;
            if(i+1<n && j-2>=0)
            c++;
            if(i-1>=0 && j-2>=0)
            c++;
            if(i-2>=0 && j+1<m)
            c++;
            if(i-2>=0 && j-1>=0)
            c++;
            res = (res +(tot-c))%1000000007;
            c=1;
        }
    }
    return res;
}
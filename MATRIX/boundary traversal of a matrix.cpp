// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends



class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
    {
        // code here
        int tl =0;
        int tr = 0;
        int br = m-1;
        int bl = n-1;
        vector<int> res;
        
        if(n==1)
        {
            for(int j=0;j<m;j++)
            {
                res.push_back(matrix[0][j]);
            }
            return res;
        }
        
        if(m==1)
        {
            for(int j=0;j<n;j++)
            {
                res.push_back(matrix[j][0]);
            }
            return res;
        }
        
        while(tl<m-1)
        {
            res.push_back(matrix[0][tl]);
            tl++;
        }
        while(tr<n-1)
        {
            res.push_back(matrix[tr][m-1]);
            tr++;
        }
        while(br>0)
        {
            res.push_back(matrix[n-1][br]);
            br--;
        }
        while(bl>0)
        {
            res.push_back(matrix[bl][0]);
            bl--;
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
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

void helper(vector<vector<char>>& grid, int n, int m, int i, int j)

{
    if(i>=0 and i<n and j>=0 and j<m and grid[i][j]=='1')
    {
        grid[i][j]='2';
        helper(grid, n, m, i, j+1);
        helper(grid, n, m, i, j-1);
        helper(grid, n, m, i+1, j);
        helper(grid, n, m, i-1, j);
        helper(grid, n, m, i+1, j+1);
        helper(grid, n, m, i-1, j+1);
        helper(grid, n, m, i+1, j-1);
        helper(grid, n, m, i-1, j-1);
        
    }
}
class Solution
{
    public:
    //Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) 
    {
        // Code here
        int cnt =0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    helper(grid,n, m, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends
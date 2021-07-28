#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

int dfs(int i, int j, int n, int m, vector<vector<int>>& grid)
{
    if(i<0||j<0||i>=n||j>=m)
    {
         return 0;
    }
    if(grid[i][j]==0)
    {
        return 0;
    }
    grid[i][j] = 0;
    
    return 1+dfs(i+1,j,n,m,grid)+dfs(i-1,j,n,m,grid)+dfs(i,j-1,n,m,grid)+dfs(i,j+1,n,m,grid)+dfs(i-1,j-1,n,m,grid)+dfs(i+1,j+1,n,m,grid)+dfs(i-1,j+1,n,m,grid)+dfs(i+1,j-1,n,m,grid);
}

class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int area=0;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    area = max(area, dfs(i, j, n, m, grid));
                }
            }
        }
        return area;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

bool helper(int i, int j, int row, int col, vector<vector<int>>& grid)
{
    if(i<0||i>=row || j<0 || j>=col)
    {
        return false;
    }
    if(grid[i][j] == 0)
    {
        return false;
    }
    if(grid[i][j]==2)
    {
        return true;
    }
    grid[i][j]=0;
    
    bool a1 = helper(i+1, j, row, col, grid);
    bool a2 = helper(i-1, j, row, col, grid);
    bool a3 = helper(i, j+1, row, col, grid);
    bool a4 = helper(i, j-1, row, col, grid);
    return (a1||a2||a3||a4);
    
}

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int row = grid.size();
        int col = grid[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j] == 1)
                {
                    if(helper(i, j, row, col, grid) ==  true)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends
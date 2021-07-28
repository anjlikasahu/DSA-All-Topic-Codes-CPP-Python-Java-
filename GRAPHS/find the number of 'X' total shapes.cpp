#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

void dfs(vector<vector<char>>& grid, int i, int j , int n, int m)
{
    if(i<0||i>=n||j<0||j>=m||grid[i][j]!='X')
    {
        return;
    }
    grid[i][j] = 'O';
    dfs(grid, i - 1, j, n, m);
    dfs(grid, i, j - 1, n, m);
    dfs(grid, i, j + 1, n, m);
    dfs(grid, i + 1, j, n, m);
}

class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) 
    {
        int n = grid.size();
int m = grid[0].size();
int cnt = 0;
for (int i = 0; i < n ; i++) {
for (int j = 0; j < m ; j++) {
if (grid[i][j] == 'X') {
dfs(grid, i, j, n, m);
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
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends
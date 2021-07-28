class Solution
{
    public:
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        int N = grid.size();
        int M = grid[0].size();
        
        vector<vector<int>> res(N, (vector<int> (M, INT_MAX)));
        
        queue<pair<int, int="">> q;
        
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push({i, j});
                    
                    res[i][j] = 0;
                }
            }
        }
        
        vector<pair<int, int="">> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while(!q.empty())
        {
            int currX = q.front().first;
            int currY = q.front().second;
            
            q.pop();
            
            for(auto move: moves)
            {
                int x = currX + move.first;
                int y = currY + move.second;
                
                if(x >= 0 and x < N and y >= 0 and y < M)
                { 
                    if(res[x][y] > res[currX][currY] + 1)
                    {
                        res[x][y] = res[currX][currY] + 1;
                        
                        q.push({x, y});
                    }
                }
            }
        }
        
        return res;
    }
};
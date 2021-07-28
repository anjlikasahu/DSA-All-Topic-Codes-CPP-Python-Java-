bool isSafe(vector<vector<int>> &mat, int n, int m, int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m && mat[i][j] == 1);
}

int rotOranges(vector<vector<int>> &mat, int n, int m)
{
    int timer = -1;
    
    queue<pair<int, int="">> q;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(mat[i][j] == 2)
            {
                q.push({i, j});
                
                mat[i][j] = 3;
            }
        }
    }
    
    while(q.empty() == false)
    {
        int count = q.size();
        
        for(int k = 0; k < count; k++)
        {
            auto index = q.front();
            int i = index.first;
            int j = index.second;
            
            if(isSafe(mat, n, m, i, j+1) == true)
            {
                q.push({i, j+1});
                
                mat[i][j+1] = 3;
            }
            
            if(isSafe(mat, n, m, i+1, j) == true)
            {
                q.push({i+1, j});
                
                mat[i+1][j] = 3;
            }
            
            if(isSafe(mat, n, m, i, j-1) == true)
            {
                q.push({i, j-1});
                
                mat[i][j-1] = 3;
            }
            
            if(isSafe(mat, n, m, i-1, j) == true)
            {
                q.push({i-1, j});
                
                mat[i-1][j] = 3;
            }
            
            q.pop();
        }
        
        timer++;
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(mat[i][j] == 1)
            {
                return -1;
            }
        }
    }
    
    return timer;
}
int shortest(vector<vector<int> > &grid, int n) {
    set<pair<int,pair<int,int> > >q;
    int dist[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j] = INT_MAX;
        }
    }
    dist[0][0] = grid[0][0];
    q.insert({grid[0][0],{0,0}});
    while(!q.empty()){
        pair<int,pair<int,int> >f = *(q.begin());
        q.erase(q.begin());
        int d = f.first;
        int si = f.second.first;
        int sj = f.second.second;
        for(int i=0;i<4;i++){
            int ni = si+dir[i][0];
            int nj = sj+dir[i][1];
            if(ni<0 || nj<0 || ni>=n || nj>=n || (d+grid[ni][nj]>=dist[ni][nj])) continue;
            dist[ni][nj] = d+grid[ni][nj];
            q.insert({d+grid[ni][nj],{ni,nj}});
        }
    }
    return dist[n-1][n-1];
}
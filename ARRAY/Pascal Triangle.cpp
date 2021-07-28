vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>>res(A);
    
    for(int i=0;i<A;i++)
    {
        for(int j=0; j<=i; j++)
        {
            res[i].push_back(1);
        }
    }
    for(int i=2;i<A;i++)
    {
        for(int j=1;j<i;j++)
        {
            res[i][j] = res[i-1][j] + res[i-1][j-1];
        }
    }
    return res;
    
}

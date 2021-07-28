vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    int n = A.size();
    vector<int>res;
    sort(A.rbegin(),A.rend());
    sort(B.rbegin(),B.rend());
    priority_queue<pair<int, pair<int, int>>>pq;
    
    for(int i=0;i<n;i++)
    {
        pq.push({A[0]+B[i], {0,i}});
    }
    while(res.size()<n)
    {
        auto p = pq.top();
        pq.pop();
        res.push_back(p.first);
        auto idx = p.second;
        int i = idx.first;
        int j = idx.second;
        pq.push({A[i+1]+B[j], {i+1,j}});
    }
    return res;
}



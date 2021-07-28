int Solution::solve(vector<int> &A, int B) {
    int i=0;
    int j;
    int ans=0;
    int sum=0;
    for(j=0;j<A.size();j++)
    {
        sum+=A[j];
        while(sum>=B)
        {
            sum-=A[i];
            i++;
        }
        if(sum<B)
        {
            ans+=(j-i+1);
        }

    }
    return ans;


}

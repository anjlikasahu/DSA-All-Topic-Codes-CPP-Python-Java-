int Solution::nTriang(vector<int> &A) {
      sort(A.begin(),A.end());
    int mod=1000000007;
    int n=A.size();
    int count=0;
    for(int i=n-1;i>1;i--)
    {
        int s=0;
        int e=i-1;
        if(A[i]==0)
            continue;
            
        while(s<e)
        {
            if(A[s]+A[e]>A[i])
                {count+=e-s;
                e--;}
            else
                s++;
            
            count=count%mod;
        }
    }
    return count;
}

int Solution::solve(vector<int> &A, int B){
    int i=0;
    int j=0;
    int ans =0;
    int cnt=0;
    while(j<A.size())
    {
        if(A[j]==0)
        {
           cnt++;
        }
        while(cnt>B)
        {
            if(A[i]==0)
            {
                cnt--;
            }
            i++;
        }
        if(j-i+1 > ans)
        {
            ans = j-i+1;
        }
        
        j++;

    }
    return ans;
    }

int maximumSumSubarray(int K, vector<int> &A , int N){
        // code here 
        int n = A.size();
        int sum =0;
        int ans;
        for(int i=0;i<K;i++)
        {
            sum+=A[i];
        }
        ans =sum;
        int i=1;
        int j=K;
        while(j<n)
        {
            sum = sum - A[i-1]+A[j];
            ans = max(sum, ans);
            i++;
            j++;
        }
        return ans;
        
    }
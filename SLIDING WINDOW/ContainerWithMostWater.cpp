int Solution::maxArea(vector<int> &A) {
    int i=0;
    int j=A.size()-1;
    int ans = (j-i)*min(A[i], A[j]);
    while(i<j)
    {
        if((j-i)*min(A[i], A[j]) > ans)
        {
            ans = (j-i)*min(A[i], A[j]);
        }
        if(A[i]<A[j])i++;
        else j--;
    }
    return ans;
}



int Solution::diffPossible(vector<int> &A, int B) {
    int n = A.size();
    int l =0;
    int h=1;
    while(l<n && h<n)
    {
        if(l==h)
        {
           h++;
        }
        else
        {
        int diff = A[h]-A[l];
        if(diff ==B)
        {
            return 1;
        }
        else if(diff<B)
        {
            h--;
        }
        else{
           l++;
        }
        }
    
        }
        return 0;
        
}

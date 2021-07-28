void Solution::merge(vector<int> &A, vector<int> &B) {
    int a=A.size()-1;
    int b=B.size()-1;
    A.resize(a+b);
    while(a>=0 && b>=0)
    {
        if(A[a]<B[b])
        {
           A[a+b+1] = B[b];
           b--;
        }
        else
        {
            A[a+b+1] = A[a]; 
            a--;
            
        }
    }
    while(b>=0)
    {
        A[b] = B[b];
        b--;
    }
    
}

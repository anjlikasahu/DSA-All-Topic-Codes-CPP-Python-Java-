int swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
void Solution::sortColors(vector<int> &A) {
    int n = A.size();
    int pos =0;
    for(int i=0;i<n;i++)
    {
        if(A[i]==0)
        {
            swap(A[i], A[pos]);
            pos++;
        }
    }
    pos = n-1;
    for(int i=n-1;i>=0;i--)
    {
        if(A[i]==2)
        {
            swap(A[i], A[pos]);
            pos--;
        }
    }
    
}

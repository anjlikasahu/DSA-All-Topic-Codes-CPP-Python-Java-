int Solution::threeSumClosest(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    int closestsum = INT_MAX-1;
    for(int i=0;i<A.size()-2;i++)
    {
        int l =i+1;
        int h=A.size()-1;
        {
            while(l<h)
            {
                int sum = A[i]+A[l]+A[h];
                if(sum==B)
                {
                    return sum;
                }
                if(abs(B-sum)<abs(B-closestsum))
                {
                    closestsum = sum;
                }
                if(sum>B)
                {
                    h--;
                }
                else
                {
                    l++;
                }
            }
        }
    }
    return closestsum;
    

}

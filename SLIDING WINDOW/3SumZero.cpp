vector<vector<int> > Solution::threeSum(vector<int> &A) {
    vector<vector<int>>res;
    unordered_set<int>st;
    vector<int>temp;
    if(A.size()<3)
    return res;
    sort(A.begin(), A.end());
    for(int i=0;i<A.size()-2;i++)
    {
        //if(i>0 && A[i]==A[i+1]) continue;
        
        int l = i+1;
        int h = A.size()-1;
        while(l<h)
        {
            long sum = (long)A[i]+(long)A[l]+(long)A[h];
            if(sum==0 && st.find(100*A[i] + 10*A[l] + A[h]) == st.end())
            {
                temp.push_back(A[i]);
                temp.push_back(A[l]);
                temp.push_back(A[h]);
                res.push_back(temp);
                temp.clear();
                st.insert(100*A[i] + 10*A[l] + A[h]);
                l++;
                h--;
            }
            else if(sum>0)
            {
                h--;
            }
            else{
                l++;
            }
        }
    }
    return res;

}

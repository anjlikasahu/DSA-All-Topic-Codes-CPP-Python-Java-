int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int i=0,j=0,k=0;
    int ans =INT_MAX;
    
    while(i<A.size() && j<B.size() && k<C.size())
    {
      ans = min(ans, max(max(abs(A[i]-B[j]), abs(B[j]-C[k])), abs(A[i]-C[k])));
      //ans = min(ans,max(max(abs(A[i]-B[j]),abs(B[j]-C[k])),abs(C[k]-A[i])));
      if(B[j]<=A[i] && B[j]<=C[k]) j++;
      else if(C[k]<=B[j] && C[k]<A[i]) k++;
      else if(A[i]<=B[j] && A[i]<= C[k]) i++;
    return ans;

}
}

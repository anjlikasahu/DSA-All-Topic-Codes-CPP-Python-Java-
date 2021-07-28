int Solution::removeElement(vector<int> &A, int B) {
   vector<int> res;
   int cnt;
   for(int i=0;i<A.size();i++)
   {
       if(A[i]!=B)
       {
           res.push_back(A[i]);
       }
   }
   A.clear();
   A = res;
   return A.size();
}

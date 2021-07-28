int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size() <= 2) return(A.size());
int idx = 2;
for(int i = 2 ; i < A.size() ; i++) {
if(A.at(i) != A.at(idx - 1) || A.at(i) != A.at(idx - 2)) A.at(idx++) = A.at(i);
}
return(idx);
    
}

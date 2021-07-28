int Solution::removeDuplicates(vector<int> &A) {
    int n = A.size();
    unordered_set<int>s(A.begin(), A.end());
    A.clear();
    for(auto x:s)
    A.push_back(x);

    return s.size();

}

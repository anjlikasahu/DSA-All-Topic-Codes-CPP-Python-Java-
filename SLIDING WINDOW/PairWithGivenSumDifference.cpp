int Solution::solve(vector<int> &A, int B) {
    if(A.empty()) return 0;
int N = A.size() - 1;
sort(A.begin(), A.end());

        int i = 0, j = 1, diff = 0;
        while(i <= N && j <=N){
            diff = A[j] - A[i];
            if(i != j && diff == B) return 1;
            else if(diff < B) j++;
            else i++;
        }
        return 0;
}

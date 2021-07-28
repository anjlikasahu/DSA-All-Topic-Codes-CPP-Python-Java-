#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

void realSubset (vector<int> &nums, vector<int> &temp, int i, vector<vector<int>> &ans, bool previous){

if(i==nums.size()){
ans.push_back(temp);
return ;
}
else{
realSubset(nums,temp, i+1, ans,false);
if (i>=1 && nums[i]==nums[i-1] && !previous){
return;
}

temp.push_back(nums[i]);
realSubset(nums, temp, i+1, ans,true);

temp.pop_back();

}
}

class Solution
{
    public:
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> nums, int n)
    {sort(nums.begin(), nums.end());
vector<vector <int>> ans;
vector<int> temp;
realSubset(nums,temp, 0, ans,false);
sort(ans.begin(), ans.end());
return ans;
    }
};



// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends
#include<iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int helper(TreeNode* A,int &res){

    if(A==nullptr)
        return 0;

    int l=helper(A->left,res);
    int r=helper(A->right,res);

    int temp=max(l,r)+A->val;
    if(A->left==NULL && A->right == NULL)
        temp=max(temp,A->val);
    int ans=max(temp,l+r+A->val);
    res=max(ans,res);
    return temp;
}

int maxPathSum(TreeNode* A) {
    int res=INT32_MIN;
    helper(A,res);
    return res;
}

int main(){
  TreeNode *root = new TreeNode(1);
  root->left        = new TreeNode(2);
  root->right       = new TreeNode(3);
  root->left->left  = new TreeNode(4);
  root->left->right = new TreeNode(5);
  cout<<maxPathSum(root);
}


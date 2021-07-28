class trienode{
    public:
    trienode *left;
    trienode *right;
};

void insert(trienode *curr, int n)
{
    trienode *root = curr;
    for(int i=31;i>=0;i--)
    {
        int val = (n>>i)&1;
        if(val==0)
        {
            if(root->left==nullptr)
            {
                root->left = new trienode();
            }
            root=root->left;
            
        }
        else
        {
            if(root->right==nullptr)
            {
                root->right = new trienode();   
            }
            root = root->right;
            
        }
    }
}

int find(trienode *curr, vector<int>v)
{
    int ans = INT_MIN;
    for(int j=0;j<v.size();j++)
    {
        int curr_xor = 0;
        int val = v[j];
        trienode *root = curr;
        for(int i=31;i>=0;i--)
        {
            int b = (val>>i)&1;
            if(b==0)
            {
                if(root->right)
                {
                    curr_xor += pow(2,i);
                    root=root->right;
                }
                else
                {
                    root=root->left;
                }
            }
            else
            {
                if(root->left)
                {
                    curr_xor += pow(2,i);
                    root=root->left;
                }
                else
                {
                    root=root->right;
                }
            }
        }
        ans = max(ans, curr_xor);
    }
    return ans;
}

int Solution::solve(vector<int> &A, vector<int> &B) {
    trienode *root = new trienode();
    for(int i=0;i<A.size();i++)
    {
        insert(root, A[i]);
    }
    return(find(root, B));
    
}

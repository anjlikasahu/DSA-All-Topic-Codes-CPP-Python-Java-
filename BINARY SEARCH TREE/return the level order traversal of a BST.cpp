// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNewNode(int value)
{
    Node *temp=new Node;
    temp->data=value;
    temp->left=temp->right=NULL;
    return temp;
}

Node *newNode(Node *root,int data)
{
    if(root==NULL)
    root=createNewNode(data);
    else if(data<root->data)
    root->left=newNode(root->left,data);
    else
    root->right=newNode(root->right,data);
    return root;
    
}


 // } Driver Code Ends
//User function Template for C++


//Function to return the level order traversal of a BST.
vector<int> levelOrder(struct Node* root)
{
    // code here 
    vector<int> res;
    queue<Node*>q;
    if(root==NULL)
    {
        return res;
    }
    q.push(root);
    while(q.empty()==false)
    {
        int cnt = q.size();
        for(int i=0;i<cnt;i++)
        {
            Node *curr=q.front();
            q.pop();
            res.push_back(curr->data);
            if(curr->left!=NULL)
            {
                q.push(curr->left);
            }
            if(curr->right!=NULL)
            {
                q.push(curr->right);
            }
            
        }
    }
    return res;
}

// { Driver Code Starts.



int main() {
    
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        Node *root=NULL;
        int sizeOfArray;
        cin>>sizeOfArray;
        int arr[sizeOfArray];
        
        for(int i=0;i<sizeOfArray;i++)
        cin>>arr[i];
        
        for(int i=0;i<sizeOfArray;i++)
        {
            root=newNode(root,arr[i]);
        }
        
        vector <int> res = levelOrder(root);
        for (int i : res) cout << i << " ";
        cout << endl;
        
        
    }
	return 0;
}  // } Driver Code Ends
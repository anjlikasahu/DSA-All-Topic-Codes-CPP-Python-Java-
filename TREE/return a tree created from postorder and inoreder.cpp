/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.

Node* helper(int in[], int post[], int is, int ie, int &postindex)
{
    if(is>ie)
    {
        return NULL;
    }
    Node *root = new Node(post[postindex--]);
    int inindex=0;
    for(int i=is;i<=ie;i++)
    {
        if(in[i]==root->data)
        {
            inindex=i;
            break;
        }
    }
    root->right = helper(in , post, inindex+1, ie, postindex);
    root->left = helper(in , post, is, inindex-1, postindex);
    
    return root;
    
}
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int postindex = n-1;
    return helper(in, post, 0, n-1, postindex);
}

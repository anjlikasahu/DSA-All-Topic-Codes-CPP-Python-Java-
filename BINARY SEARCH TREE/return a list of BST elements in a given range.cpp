using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

vector<int> printNearNodes(Node*root,int k1 , int k2);

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        int k1 , k2;
        string s;
		getline(cin,s);
		scanf("%d ", &k1);
		scanf("%d " , &k2);
        Node* root = buildTree(s);
        vector <int> res = printNearNodes(root, k1 ,  k2);
        for (int i=0;i<res.size();i++) cout << res[i] << " ";
        cout<<endl;
    }
    return 1;
}// } Driver Code Ends






//Function to return a list of BST elements in a given range.
Node* helper(Node *root, vector<int> &res)
{
    if(root!=NULL)
    {
        helper(root->left, res);
        res.push_back(root->data);
        helper(root->right, res);
    }
}
vector<int> printNearNodes(Node *root, int low, int high)
{
  // your code goes here
  vector<int> res;
  helper(root, res);
  vector<int> ans;
  for(int i=0;i<res.size();i++)
  {
      if(res[i]>=low && res[i]<=high)
      {
          ans.push_back(res[i]);
      }
      if(res[i]>high)
      {
          break;
      }
  }
  return ans;
  
}

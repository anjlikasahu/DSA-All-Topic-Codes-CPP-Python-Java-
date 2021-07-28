using namespace std;

 // } Driver Code Ends

void dfs(int u, stack<int> &st, bool visited[], vector<int> adj[])
{
    visited[u]=true;
    for(v : adj[u])
    {
        if(visited[v]==false)
        {
            dfs(v, st, visited, adj);
        }
    }
    st.push(u);
}

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> res;
	    stack<int> st;
	    bool visited[V];
	    for(int i=0;i<V;i++)
	    {
	        visited[i]=false;
	    }
	    for(int i=0;i<V;i++)
	    {
	        if(visited[i]==false)
	        {
	            dfs(i, st, visited, adj);
	        }
	    }
	    while(st.empty()==false)
	    {
	        res.push_back(st.top());
	        st.pop();
	    }
	    return res;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends
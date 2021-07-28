#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

void helper(vector<int> adj[], bool visited[], int s, vector<int> &res)
{
    visited[s]=true;
    res.push_back(s);
    for(auto x: adj[s])
    {
        if(visited[x]==false)
        {
            helper(adj, visited, x, res);
        }
    }
}
class Solution 
{
    public:
	//Function to return a list containing the DFS traversal of the graph.
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    vector<int> res;
	    bool visited[V];
	    for(int i=0;i<V;i++)
	    {
	        visited[i]=false;
	    }
	    for(int i=0;i<V;i++)
	    {
	        if(visited[i]==false)
	        {
	            helper(adj, visited, i, res);
	        }
	    }
	    return res;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends
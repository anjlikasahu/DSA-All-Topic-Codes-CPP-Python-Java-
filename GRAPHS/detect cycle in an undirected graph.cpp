#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

bool helper(vector<int> adj[], int s, bool visited[], int parent)
{
    visited[s]=true;
    for(auto u: adj[s])
    {
        if(visited[u]==false)
        {
            if(helper(adj, u, visited, s) == true)
            {
                return true;
            }
        }
        else if(u!=parent)
        {
            return true;
        }
    }
    return false;
}

class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    bool visited[V];
	    for(int i=0;i<V;i++)
	    {
	        visited[i]=false;
	    }
	    
	    for(int i=0;i<V;i++)
	    {
	        if(visited[i]==false)
	        {
	            if(helper(adj, i, visited, -1) == true)
	            {
	                
	            return true;
	            }
	        }
	    }
	    return false;
	                
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


void dfs(vector<int> adj[], bool visited[], int s, int d, int &cnt)
{
    visited[s] = true;
    if(s==d)
    {
        cnt++;
    }
    else
    {
        for(auto u: adj[s])
        {
            if(visited[u]==false)
            {
                dfs(adj, visited, u, d, cnt);
                visited[u] = false;
            }
        }
    }
}

class Solution 
{
    public:
    //Function to count paths between two vertices in a directed graph.
	int countPaths(int V, vector<int> adj[], int s, int d)
	{
	    // Code here
	    bool visited[V+1] = {0};
	    int cnt =0;
	    dfs(adj, visited, s, d, cnt);
	    return cnt;
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
    		// adj[v].push_back(u);
    	}
    	int source, destination;
    	cin >> source >> destination;
        Solution obj;
        cout<<obj.countPaths(V, adj,source,destination)<<endl;
	}
	return 0;
}  // } Driver Code Ends
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

void dfs(int src,vector<bool> &vis,vector<int> adj[]){
    vis[src]=true;
    for(int i=0;i<adj[src].size();i++){
        if(vis[adj[src][i]]==false)
            dfs(adj[src][i],vis,adj);
    }
}

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int n, vector<int>adj[])
	{
	    // Code here
	    int mother=0;
    vector<bool> vis(n,false);
    for(int i=0;i<n;i++){
        if(vis[i]==false)
            {
            dfs(i,vis,adj);
            mother=i;
            }

    }
    
     vector<bool> visited(n,false);
        dfs(mother,visited,adj);
        for(int i=0;i<n;i++){
            if(visited[i]==false)
                mother=-1;
        }
    return mother;
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
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
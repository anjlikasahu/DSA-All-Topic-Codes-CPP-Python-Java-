#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

bool helper(vector<int> adj[], int s, bool visited[], bool recst[])
{
    visited[s]=true;
    recst[s]=true;
    
    for(auto u: adj[s])
    {
        if(visited[u]==false && helper(adj, u, visited, recst)==true)
        {
            return true;
        }
        else if(recst[u] == true)
        {
            return true;
        }
    }
    recst[s]=false;
    return false;
}

class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	// code here
	   	bool visited[V];
	   	bool recst[V];
	   	for(int i=0;i<V;i++)
	   	{
	   	    visited[i]=false;
	   	    recst[i]=false;
	   	}
	   	for(int i=0;i<V;i++)
	   	{
	   	    if(visited[i]==false)
	   	    {
	   	        if(helper(adj, i, visited, recst) == true)
	   	        {
	   	            return true;
	   	        }
	   	    }
	   	}
	   	return false;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
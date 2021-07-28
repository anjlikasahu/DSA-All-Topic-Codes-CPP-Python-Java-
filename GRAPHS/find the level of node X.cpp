#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    int cnt = -1;
	    bool visited[V];
	    for(int i=0;i<V;i++)
	    {
	        visited[i]=false;
	    }
	    queue<int> q;
	    
	    visited[0] = true;
	    q.push(0);
	    while(q.empty()==false)
	    {
	        int size = q.size();
	        cnt++;
	        for(int i=0;i<size;i++)
	        {
	        int u=q.front();
	        q.pop();
	        if(u==X)
return cnt;
	        for(int x : adj[u])
	        {
	            if(visited[x]==false)
	            {
	       
	                visited[x]=true;
	                q.push(x);
	            }
	        }
	      }
	    }
	    return -1;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

bool issafe(bool graph[101][101], int V, int v, int i, int color[])
{
    for(int k=0;k<V;k++)
    {
        if(graph[v][k]==true && color[k]==i)
        {
            return false;
        }
    }
    return true;
}

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool check(bool graph[101][101], int V, int v, int color[], int m)
{
    if(v==V)
    {
        return true;
    }
    for(int i=1;i<=m;i++)
    {
        if(issafe(graph, V, v, i, color))
        {
            color[v]=i;
        if(check(graph, V, v+1, color, m) == true)
        {
            return true;
        }
        color[v]=0;
        }
        
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    int color[V+1]={0};
    return check(graph, V, 0, color, m);
    
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
vector <int> dijkstra(vector<vector<int>> graph, int src, int V)
{
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    
    vector<bool> fin(V, false);
    
    priority_queue<pair<int, int="">, vector<pair<int, int="">>, greater<pair<int, int="">>> pq;
    pq.push({0, src});
    
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        
        fin[u] = true;
        
        for(int v = 0; v < V; v++)
        {
            if(graph[u][v] != 0 && fin[v] == false)
            {
                if(dist[v] > dist[u] + graph[u][v])
                {
                    dist[v] = dist[u] + graph[u][v];
                    pq.push({dist[v], v});
                }
            }
        }
    }
    
    return dist;
}
void dfs(int s,list<int>adj[],bool visit[])
{
visit[s]=true;
for(auto it=adj[s].begin();it!=adj[s].end();it++)
{
if(!visit[*it])
dfs(*it,adj,visit);
}
}
bool Graph::isBridge(int u, int v) {

bool visit[V]={0};
adj[u].remove(v);
adj[v].remove(u);
dfs(v,adj,visit);
if(!visit[u])
return true;
return false;
}
#define pii pair<int,int>
int spanningTree(int V,int E,vector<vector<int> > graph)
{
   int vis[V]; // vis tells if a vertex has been included in the mst
   int val[V];
   
   for(int i=0;i<V;i++)
   {
       vis[i]=0;
       val[i]=INT_MAX;
   }

   val[0]=0;
     
   priority_queue<pii,vector<pii>,greater<pii>> pq;
   
   pq.push(make_pair(val[0],0)); //{value,key} because ordering is done 
                                 // according to the first element
   
   for(int i=1;i<V;i++)
   {
       pq.push(make_pair(INT_MAX,i));
   }
   
   int cost = 0;
   
   while(!pq.empty())
   {  
       pii u =pq.top();
       pq.pop();
       int i = u.second;
       
       if(!vis[i]){
       vis[i]=1;
       cost+=val[i];
       for(int j=0;j<graph[i].size();j++)
       {
        
        if(graph[i][j]!=INT_MAX && !vis[j] && graph[i][j]<val[j] )
           {
               val[j]=graph[i][j];
               pq.push(make_pair(val[j],j));
           }
       }
       }
   }
   return cost;
}
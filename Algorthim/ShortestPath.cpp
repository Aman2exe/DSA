int shortestpath(int n , vector<vector<int>> &adj , int st , int en){
   vector<int> val(n,n);
   val[st]=0 ;
   priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> qu;
   qu.push({0,st});
   while(!qu.empty()){
   int dis=qu.top().first , i=qu.top().second ;
   qu.pop();
   for(int j=0 ; j<adj[i].size() ; j++){
    if(val[adj[i][j]]>(dis+1)){
        val[adj[i][j]]=dis+1 ;
        qu.push({dis+1,adj[i][j]});
    }
   } 
   }
   return val[en];  
}

//-------------------------------------------------------------------------------------------------------------------//

int Dijkstra(int n , vector<vector<pair<int,int>>> &adj , int st , int en){
   vector<int> val(n,LLONG_MAX);
   val[st]=0 ;
   priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> qu;
   qu.push({0,st});
   while(!qu.empty( )){
   int dis=qu.top().first , i=qu.top().second ;
   qu.pop();
   for(int j=0 ; j<adj[i].size() ; j++){
    if(val[adj[i][j].first]>(dis+adj[i][j].second)){
        val[adj[i][j].first]=dis+adj[i][j].second ;
        qu.push({dis+adj[i][j].second,adj[i][j].first});
    }
   } 
   }
   if(val[en]==LLONG_MAX) return -1 ;
   return val[en];  
}
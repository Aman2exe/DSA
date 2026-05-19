#include <bits/stdc++.h>
using namespace std;

class union_rank{
    public:
    vector<int>rank , par ;
    union_rank(int n){
       rank.resize(n+1,0);
       par.resize(n+1);
       for(int i=0 ; i<=n ; i++) par[i]=i ;
    }
    int parent(int v){
       if(par[v]==v) return v ;
       return par[v]=parent(par[v]);
    }
    void add(int v , int u){
      int pv=parent(v),pu=parent(u);
      if(pv==pu) return ;
      if(rank[pv]>rank[pu]){
         par[pu]=pv ;
      }
      else if(rank[pv]<rank[pu]){
         par[pv]=pu ;
      }
      else{
        par[pu]=pv ;
        rank[pv]++ ;
      }
    }
    bool check(int v , int u){
        if(parent(u)==parent(v)) return true ;
        return false ;
    }
};
int kruskal(int n, vector<pair<int,pair<int,int>>>vec){
    int ans=0 ;
    union_rank tt(n);
    for(int i=0 ; i<vec.size(); i++){
     int w=vec[i].first, a = vec[i].second.first , b=vec[i].second.second ;
     if(!tt.check(a,b)){
         ans+=w ;
         tt.add(a,b);
     }
    }
    return ans ;
}
int main() {
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>>vec(m);
    for(int i=0 ; i<m ; i++){
        int a, b , c ; 
        cin>>a>>b>>c ; // edges , edges , weights
        vec[i]={c,{a,b}};
    }
    sort(vec.begin(),vec.end());
    cout<<kruskal(n,vec)<<endl ;
    return 0;
}
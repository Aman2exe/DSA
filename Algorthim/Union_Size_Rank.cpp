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

class union_size{
    public:
    vector<int>size , par ;
    union_size(int n){
       size.resize(n+1,1);
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
      if(size[pv]>size[pu]){
         par[pu]=pv ;
         size[pv]=size[pv]+size[pu] ;
      }
      else if(size[pv]<size[pu]){
         par[pv]=pu ;
         size[pu]=size[pv]+size[pu] ;
      }
      else{
        par[pu]=pv ;
        size[pv]=size[pv]+size[pu] ;
      }
    }
    bool check(int v , int u){
        if(parent(u)==parent(v)) return true ;
        return false ;
    }
};

int main() {
    int n ;
    cin>>n ;
    union_rank tt(n);
    int m ; cin>>m ;
    for(int i=0 ; i<m ; i++){
        int a , b ;
        cin>>a>>b ;
        tt.add(a,b);
    }
    int ch ;
    cin>>ch ;
    for(int i=0 ; i<ch ; i++){
        int a , b ;
        cin>>a>>b ;
        cout<<tt.check(a,b)<<endl ;
    }
    return 0;
}
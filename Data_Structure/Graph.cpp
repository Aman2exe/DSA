#include <bits/stdc++.h>
using namespace std ;
int main(){

    int n,cnt ;
    cin>>n>>cnt ;
    vector<vector<int>>vec(n);
    for(int i=0 ; i<cnt ; i++){
        int a , b ; cin>>a>>b ;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    // BFS 
    stack<int>st ;
    vector<int>vis(n,false);
    int bfs=0 ;
    for(int i=0 ; i<n ; i++){
        if(!vis[i]){
            bfs++ ;
            st.push(i);
            vis[0]=true ;
            while(!st.empty()){
              stack<int>temp ;
              while(!st.empty()){
                int tt=st.top();
                st.pop();
                for(int j=0 ; j<vec[tt].size() ; j++){
                    if(!vis[vec[tt][j]]){
                      temp.push(vec[tt][j]);
                      vis[vec[tt][j]]=true ;
                    }
                }
              }
              st=temp;
            }
        }
    }
    cout<<"No of Comp. by BFS "<<bfs<<" by DFS ";

    // DFS
    stack<int>stt ;
    vector<int>viss(n,false);
    int dfs=0 ;
    for(int i=0 ; i<n ; i++){
        if(viss[i]) continue;
        dfs++ ;
        stt.push(i);
        while(!stt.empty()){
            int tt=stt.top();
            stt.pop();
            if(!viss[tt]){
                viss[tt]=1 ;
                for(int j=0 ; j<vec[tt].size() ; j++){
                  stt.push(vec[tt][j]);
                }
            }
        }
    }
    cout<<dfs<<endl ;

}
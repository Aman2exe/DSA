#include <bits/stdc++.h>
using namespace std;
class node{
    public: 
     node *a[26]={NULL};
     bool flag;
     node(){flag=false;}
};
class trie{
    public:
    node* root ;
     trie(){
        root=new node();
    }
    void insert(string &str){
        node *temp=root ;
        for(int i=0 ; i<str.size() ; i++){
          if(temp->a[str[i]-'a']==NULL){
           temp->a[str[i]-'a']=new node();
           temp=temp->a[str[i]-'a'];
          }
          else{
            temp=temp->a[str[i]-'a'];
          }
        }
        temp->flag=true ;
   }
    bool search(string &str){
      node *temp=root ;
      for(int i=0 ; i<str.size() ; i++){
        if(temp->a[str[i]-'a']==NULL) return false ;
        else temp=temp->a[str[i]-'a'];
      }
      if(temp->flag==false) return false ;
      return true ; 
    }
    bool startswith(string &str){
       node *temp=root ;
       for(int i=0 ; i<str.size() ; i++){
         if(temp->a[str[i]-'a']==NULL) return false ;
         else temp=temp->a[str[i]-'a'];
      }
      return true ;
    }
};
int main() {
      int n ;
      cin>>n ;
      trie*tt=new trie();
      while(n--){
        int i ; string str; cin>>i>>str ;
        if(i==1) tt->insert(str);
        else if(i==2) cout<<tt->search(str)<<endl;
        else cout<<tt->startswith(str)<<endl;
      }
      return 0 ;
}
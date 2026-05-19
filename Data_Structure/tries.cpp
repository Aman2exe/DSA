#include <bits/stdc++.h>
using namespace std;
class node{
    public: 
     node *a[26]={NULL};
     bool flag;
     node(){flag=false;}
};
class tries{
    public:
    node* root ;
    void createtries(){
        root=new node();
    }
    void inserttries(string &str){
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
    bool containword(string &str){
      node *temp=root ;
      for(int i=0 ; i<str.size() ; i++){
        if(temp->a[str[i]-'a']==NULL) return false ;
        else temp=temp->a[str[i]-'a'];
      }
      if(temp->flag==false) return false ;
      return true ; 
    }
    bool containpreffix(string &str){
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
      tries*tt=new tries();
      tt->createtries();
      while(n--){
        int i ; string str; cin>>i>>str ;
        if(i==1) tt->inserttries(str);
        else if(i==2) cout<<tt->containword(str)<<endl;
        else cout<<tt->containpreffix(str)<<endl;
      }
      return 0 ;
}
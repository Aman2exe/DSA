#include <bits/stdc++.h>
using namespace std ;
struct linklist{
    string name ;
    linklist *next ;
    linklist *prev ;
    linklist(string a){ name=a , next=NULL , prev=NULL;}
};
int main(){
    int n ;
    cin>>n ;
    linklist *head=NULL , *root=NULL;
    for(int i=0 ; i<n ; i++){
        string str ; cin>>str ;
        linklist *tt= new linklist(str);
        if(head==NULL){
            head=tt ;
            root=tt ;
        }
        else{
            root->next=tt ;
            tt->prev=root ;
            root=tt ;
        }
    }
    linklist *temp=head ;
    while(temp!=NULL){
        cout<<temp->name<<" ";
        temp=temp->next ;
    }
    cout<<endl ;
    temp=root ;
    while(temp!=NULL){
        cout<<temp->name<<" ";
        temp=temp->prev ;
    }
}
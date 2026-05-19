#include <bits/stdc++.h>
using namespace std ;
struct tree{
     int val ;
     tree* left ;
     tree* right ;
     tree(int a){val=a , left=NULL , right=NULL ;}
};
void travel(tree* root){
    if(root==NULL) return ;
    travel(root->left);
    cout<<root->val<<" ";   
    travel(root->right);
    return ;
}
int height(tree* head){
    if(head==NULL) return 0 ;
    else return max(height(head->left),height(head->right))+1 ;
}
tree* insert(tree*head , int tt){
    if(head==NULL){
        tree* node=new tree(tt);
        return node ;
    }
    if(head->val>tt){
        head->left=insert(head->left,tt);
    }
    else if(head->val<tt){
        head->right=insert(head->right,tt);
    }
    int bal=height(head->left)-height(head->right);
    if(bal>1){
        if(tt<head->left->val){
            tree*temp=head->left ;
            head->left=head->left->right ;
            temp->right=head ;
            return temp ;
        }
        else{
          tree* temp1=head->left ;
          tree* temp2=head->left->right;
          temp1->right=temp2->left;
          head->left=temp2->right ;
          temp2->left=temp1 ;
          temp2->right=head ;
          return temp2 ;
        }
    }
    if(bal<-1){
       if(tt<head->right->val){
          tree* temp1=head->right ;
          tree* temp2=head->right->left;
          temp1->left=temp2->right;
          head->right=temp2->left;
          temp2->right=temp1 ;
          temp2->left=head ;
          return temp2 ;
       }
       else{
            tree*temp=head->right ;
            head->right=head->right->left ;
            temp->left=head ;
            return temp ;
       }
    }
    return head ;
}

int main(){
    int n ;
    cin>>n ;
    tree* head=nullptr ;
    for(int i=0 ; i<n ; i++){
        int tt ; cin>>tt ;
        head=insert(head,tt);
        travel(head);
        cout<<endl ;

    }
  //  travel(head);
    return 0 ;
}
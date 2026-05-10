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
    cout<<root->val<<" ";
    travel(root->left);
    travel(root->right);
    return ;
}
int main(){ 
    tree* a=new tree(1);
    tree* b=new tree(2);
    tree* c=new tree(3);
    tree* d=new tree(4);
    tree* e=new tree(5);
    tree* f=new tree(6);
    tree* g=new tree(7);
    a->left=b ;
    a->right=c ;
    b->left=d ;
    b->right=e ;
    c->left=f ;
    c->right=g ;
    travel(a);
    return 0 ;
}
/*




*/
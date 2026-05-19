/*
Tree
-> Binary tree{Binary search tree , AVL Tree(Need balance factor), Red Black Tree(Need Tree Node Colour)}
// Red black tree rules
1. Roots && NILL colour always be black
2. Red colour Node donot have the Red child 
3. From root to NILL , on all possible path we have same number of count of black Nodes
// Rule to make them
1. Perform standard BST and colour nodes as red
2. if Node is root then colour it black 
3. Inseration nodes uncle colour
red-> parent and uncle black, grandparents red ;
black 4 type of rotation 

-> N-ary Tree(N->child) B and B+ tree 
->Heap , Trie , Segment Tree ,Fenwick Tree
*/


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

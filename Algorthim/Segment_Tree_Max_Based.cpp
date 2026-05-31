#include <bits/stdc++.h>
using namespace std;

// Segment Tree max element in a range 
void create_stm(vector<int>&vec , vector<vector<int>> &seg , int low , int high, int ind){
    if(low==high){
        seg[ind]={vec[low],low,high};
        return ;
    }
    int mid=(low+high)/2 ;
    create_stm(vec,seg,low,mid,2*ind);
    create_stm(vec,seg,mid+1,high,2*ind+1);
    seg[ind]={max(seg[ind*2][0],seg[ind*2+1][0]),low,high};

    return ;
}
void update_stm(vector<vector<int>>&seg, int low , int high , int ind,int i ,int val ){
    if(low==high){seg[ind]={val,low,high} ; return ;}
    int mid=(low+high)/2 ;
    if(i<=mid) update_stm(seg,low,mid,2*ind ,i,val);
    else update_stm(seg,mid+1,high,2*ind+1,i,val);
    seg[ind][0]=max(seg[ind*2][0],seg[ind*2+1][0]);
    return ;
}
int find_stm(vector<vector<int>>&seg , int low , int high , int l ,int r , int ind){
    if(high<l || low>r) return INT_MIN ;
    else if(low>=l&& high<=r) return seg[ind][0];
    else{
        int mid=(low+high)/2 ;
        return max(find_stm(seg,low,mid, l , r ,2*ind),find_stm(seg,mid+1,high,l,r,2*ind+1)); 
    }
    return 0 ;   
}
int main(){
    int n ;
    cin>>n ;
    vector<int>vec(n);
    for(int i=0 ; i<n ; i++) cin>>vec[i];
    vector<vector<int>>seg(4*n,vector<int>(3));
    create_stm(vec,seg,0,n-1,1);
    while(true){
        int i ;
        cin>>i ;
        if(i==0){
            int ind , val ;
            cin>>ind>>val ;
            update_stm(seg,0,n-1,1,ind,val);
        }
        else if(i==1){
            int l , r ;
            cin>>l>>r ;
            cout<<find_stm(seg,0,n-1,l,r,1);
        }
        else break ;
    }
    return 0;
}

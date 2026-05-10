void merge(int st , int stt , int end , vector<int>&vec){
    int en=stt-1,l=st;
    vector<int>ans ;
    while(st<=en && stt<=end ){
        if(vec[st]>vec[stt]){ ans.push_back(vec[stt]) ;stt++ ;}
        else {ans.push_back(vec[st]);st++;}
    }
    while(st<=en) {ans.push_back(vec[st]);st++;}
    while(stt<=end) {ans.push_back(vec[stt]);stt++;}
    for(int i=0 ; i<ans.size();i++) vec[l+i]=ans[i] ;
    return ;
}
void merge_sort(int i , int j , vector<int>&vec){
    if(i==j) return ;
    int mid=(i+j)/2 ;
    merge_sort(i,mid,vec);
    merge_sort(mid+1,j,vec);
    merge(i,mid+1,j,vec);
    return ;
}
int allsubarraysum(vector<int>vec,int n){
    int sum=0 ;
    for(int i=0 ; i<n ; i++) sum+=(vec[i]*(i+1)*(n-i));
    return sum ;
}
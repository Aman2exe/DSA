double power(int a , int b ){
    int base=a , result=1 ;
    bool sign = true ;
    if(b<0){
        b=-b ;
        sign = false ;
    }
    while(b>0){
        if(b%2==1) result=(result*base);
        base=base*base ;
        b=b>>1 ;
    }
    if(!sign) return 1.0/result ;
    return result ;
}
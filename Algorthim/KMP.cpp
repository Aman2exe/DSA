bool kmp(string main , string pattern){
        int n=main.size() , m=pattern.size();
        vector<int>pref(m,0);
        int i=1 , j=0 ;
        while(i<m){
            if(pattern[i]==pattern[j]){
                pref[i]=j+1 ;
                i++ ;
                j++ ;
            }
            else{
                if(j!=0){
                 j=pref[j-1];
                }
                else{
                    i++ ;
                }
            }
        }
        i=0 ,j=0 ; // i->main , j->pattern 
        while(i<n && j<m){
            if(main[i]==pattern[j]){
                i++;
                j++;
            }
            else{
             if(j!=0){
                j=pref[j-1];
             }
             else i++ ;
            }
        }
        if(j==m) return true ;
        else return false ;
    }
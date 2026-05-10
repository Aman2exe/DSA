bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1) return false ;
        sum/=2 ;
        vector<vector<bool>> dp(nums.size(), vector<bool>(sum + 1, false));
        sort(nums.begin(),nums.end());
        for(int i=0 ; i<nums.size();i++){
            if(nums[i]<=sum) dp[i][nums[i]]=true ;
        }
        for(int i=1 ; i<nums.size() ; i++){
          for(int j=0 ; j<=sum ; j++){
            if(dp[i-1][j]==true){
                dp[i][j]=true;
                int tt=j+nums[i];
                if(tt>sum) break ;
                dp[i][tt]=true ;
            }
          }
        }
        if(dp[nums.size()-1][sum]==true) return true ;
        return false ;
      }        
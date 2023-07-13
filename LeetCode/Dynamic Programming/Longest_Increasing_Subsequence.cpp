class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        int result = 1;
      
        for(int i= 1; i< nums.size();i++){
            for(int j= 0;j < i;j++){
                if(nums[j] < nums[i]){
                    if(dp[j]+1 > dp[i]){
                        dp[i] = dp[j] + 1;
                    }
                }
            }
            result = max(result,dp[i]);
        }
        
        return result;
        
    }
};

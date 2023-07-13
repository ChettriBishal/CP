class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
            return 0;
        
        int cnt = 0, len = 0;
        
        int prev_diff = nums[1] - nums[0];
        
        for(int i=2;i < n;i++){
            int curr_diff = nums[i] - nums[i-1];
            if(curr_diff == prev_diff){
                len++;
            }
            else{
                prev_diff = curr_diff;
                len = 0;
            }
            
            cnt += len;
        }
        
        return cnt;
    }
};

/* Or Space O(n) */
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
            return 0;
        
        vector<int> dp(n,0);
        
        if(nums[2] - nums[1] == nums[1] - nums[0]) dp[2] = 1;
        
        int res = dp[2];
        
        for(int i=3;i < n;i++){
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]){
                dp[i] = dp[i-1] + 1;
            }
            res += dp[i];            
        }
        
        return res;
    }
};

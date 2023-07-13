class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int res = INT_MAX;
        int sum =0;
        for(int right = 0;right <nums.size();right++){
            sum += nums[right];
            while(sum >= target){
                res = min(res,right-left+1);
                sum -= nums[left]; // decreasing the window size
                left++;
            }
        }
        if(res == INT_MAX) return 0;
        return res;
    }
};

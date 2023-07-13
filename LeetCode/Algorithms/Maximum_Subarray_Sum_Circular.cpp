class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        
        int minsum = nums[0], maxsum = nums[0];
        int currmin = 0, currmax = 0;
        int sum = 0;
        
        for(auto &x: nums){
            sum += x;
            currmin = min(x, currmin + x);
            currmax = max(x, currmax + x);
            maxsum = max(currmax, maxsum);
            minsum = min(currmin,minsum);
        }
        
        return maxsum > 0 ? max(maxsum, sum - minsum) : maxsum;
    }
};

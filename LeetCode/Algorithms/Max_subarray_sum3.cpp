class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum =INT_MIN;
        int curr = 0;
        for(int i=0;i<nums.size();i++){
           curr = max(nums[i],curr+ nums[i]);
           maxsum =max(curr,maxsum);
        }
        return maxsum;
    }
};

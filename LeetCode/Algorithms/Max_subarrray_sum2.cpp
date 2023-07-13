class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int run =0; // running sum 
        int mx = INT_MIN;
        for(int i=0;i<nums.size();i++){
            run = max(run,0); // if at any point running sum is negative
            run += nums[i];
            mx = max(run,mx);
        }
        return mx;
    }
};

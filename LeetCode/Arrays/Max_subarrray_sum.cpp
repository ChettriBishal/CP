class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n= nums.size();
        vector<int> prevbest(n);
        int mx = nums[0];
        prevbest[0] = nums[0];
        for(int i=1;i<n;i++){
            prevbest[i] = max(nums[i],prevbest[i-1] + nums[i]);
            mx = max(mx, prevbest[i]);
        }
        return mx;
    }
};

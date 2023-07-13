class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(all_of(nums.begin(),nums.end(),[](int x) { return x <0;})){
            return *max_element(nums.begin(),nums.end());
        }
        int res =0, sum =0;
        for(int i=0;i<nums.size();i++){
            sum = max(nums[i],sum+nums[i]);
            res = max(res,sum);
        }
        return res;
    }
};

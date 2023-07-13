class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int run =0;
        int sum = accumulate(nums.begin(),nums.end(),0);
        for(int i=0;i<nums.size();i++){
            run += nums[i];
            if(run -nums[i] == sum - run)
                return i;
        }
        return -1;
    }
};

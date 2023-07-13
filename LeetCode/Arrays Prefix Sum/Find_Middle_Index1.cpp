class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int runn =0; 
        for(int i=0;i<nums.size();i++){
            runn += nums[i];
            if(runn - nums[i] == sum - runn)
                return i;
        }
        return -1;
    }
};

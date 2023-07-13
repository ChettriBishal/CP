class Solution {
public:
    int result = 0;
    int mXOR = 0; // maximum xor 
    // knapsack based implementation 
    int countMaxOrSubsets(vector<int>& nums) {
        for(auto &x: nums)
            mXOR |= x;
        
        int curr = 0; // current xor
        maxsubset(nums,0,curr);
        
        return result;
    }
    
    void maxsubset(vector<int> & nums, int i, int curr)
    {
        if(i == nums.size()){
            if(curr == mXOR)
                result++;
            return;
        }
        
        maxsubset(nums, i+1, curr | nums[i]); // including it
        maxsubset(nums, i+1, curr); // discarding it 
    }
};

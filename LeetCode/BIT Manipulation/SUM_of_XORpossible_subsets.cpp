class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ord = 0;
        for(auto k: nums)
            ord |= k;
        return ord*pow(2,nums.size()-1);
    }
};

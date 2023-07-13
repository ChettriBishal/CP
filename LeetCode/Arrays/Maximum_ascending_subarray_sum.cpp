class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int runn = nums[0], res = INT_MIN;
        int prev = nums[0];
        for(int i=1;i<n;i++){
            if(prev < nums[i]){ // if greater than the previous element
                runn += nums[i];
            }
            else{
                res = max(res, runn);
                runn = nums[i];
            }
            prev = nums[i];
        }
        res = max(res, runn);
        
        return res;
    }
};

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res = 0;
        int i=0, j = nums.size() -1;
        while(i < j){
            res = max(res, nums[i++] + nums[j--]);
        }
        return res;
    }
};
/*
Largest with minimum
Second largest with second minimum
Third largest with third minimum...
....
*/

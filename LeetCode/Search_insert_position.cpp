class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(),nums.end(),target);
        if(it != nums.end()){
            return it- nums.begin();
        }
        auto g = upper_bound(nums.begin(),nums.end(),target);
        if(g!= nums.end())
            return (g - nums.begin()) -1;
        else
            return (g -nums.begin());
    }
};

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        int res = min(0,nums[0]);
        int sum = nums[0];
        for(int i=1;i<n;i++){
            sum += nums[i];
            res = min(sum,res);
        }
        res = abs(res);
        res+=1;
        return res;
    }
    
};

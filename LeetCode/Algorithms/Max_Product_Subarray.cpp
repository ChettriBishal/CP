class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int left = 1, right = 1, res = INT_MIN;
        
        for(int i=0;i < n;i++){
            left *= nums[i]; // from left
            right *= nums[n-i-1]; // from right
            
            res = max(res, max(left,right));
            
            left = (left ? left: 1);
            right = (right ? right: 1);
        }
        
        return res;
    }
};

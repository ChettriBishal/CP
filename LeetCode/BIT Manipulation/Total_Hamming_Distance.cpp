class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        int n = nums.size(); 
        for(int bit = 0;bit < 32;bit++){
            int cntz = 0;  // count of zeroes
           for(int i=0;i<n;i++){
              if(nums[i] & (1 << bit)) cntz ++; 
           } 
           res += (cntz * (n - cntz)); // every 0 will pair with every 1
        }
        return res;
    }
};

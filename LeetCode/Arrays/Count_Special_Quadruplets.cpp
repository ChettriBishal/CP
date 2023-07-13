class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        unordered_map<int,int> cnt;
        for(int i = n-1;i> 1; i--){
            for(int j = i -1; j> 0;j--){
                for(int k= j-1 ; k>= 0;k--){
                    int sum = nums[i] + nums[j] + nums[k];
                    if(cnt[sum] > 0)
                        res += cnt[sum];
                }
            }
            cnt[nums[i]]++;
        }
        
        return res;
    }
};

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> cnt;
        cnt[0]++; // zero subarray always present
        int sum =0, res= 0;
        for(int i=0;i<nums.size();i++){
           sum += nums[i];
            int tar = sum - k;
            if(cnt[tar] != 0)  res += cnt[tar];
            cnt[sum]++;
        }
        return res;
    }
};

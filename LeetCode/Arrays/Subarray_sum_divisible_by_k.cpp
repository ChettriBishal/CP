class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]++;
        int n =nums.size();
        int sum =0, cnt =0;
        for(int i=0;i<n;i++){
            sum = (sum + nums[i])%k;
            sum = (sum + k) %k;
            if(mp[sum] != 0)
                cnt += mp[sum]; 
            mp[sum]++;
        }
        return cnt;
    }
};

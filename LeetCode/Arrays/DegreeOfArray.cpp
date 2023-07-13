class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        
        unordered_map<int,int> freq;
        int mx = INT_MIN;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
            mx= max(mx,freq[nums[i]]);
        }
        unordered_set<int> st;
        int res = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(freq[nums[i]] == mx){
                int left= find(nums.begin(),nums.end(),nums[i]) - nums.begin();
                int right = find(nums.rbegin(),nums.rend(),nums[i]) - nums.rbegin();
                right = nums.size() - right;
                res = min(res, abs(right- left));
            }
        }
        return res;
        
    }
};

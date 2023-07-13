class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int left = 0, right;
        
        multiset<int> m;
        
        for(right = 0; right < nums.size(); right++){
            m.insert(nums[right]);
            if(*m.rbegin() - *m.begin() > limit)
                m.erase(m.find(nums[left++]));
        }
        
        return right - left;
    }
};

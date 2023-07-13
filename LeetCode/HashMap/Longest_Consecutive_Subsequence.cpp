class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> cnt;
        
        for(auto &x: nums)
            cnt[x]++;
        
        int longest_seq = 0;
        
        for(int i = 0; i< nums.size();i++){
            int lft = nums[i] -1; // to check for values less than nums[i] 
            int rgt = nums[i] + 1; // to check for values greater than nums[i] 
            int curr_seq = 1;
            
            // checking for consecutive values
            
            while(cnt[lft] > 0 && cnt[lft] != INT_MAX){ // <------ 
                cnt[lft] = INT_MAX; // to mark as visited
                lft--;
                curr_seq++;
            }
            
            while(cnt[rgt] > 0 && cnt[rgt] != INT_MAX){ // ------>
                cnt[rgt] = INT_MAX; 
                rgt++;
                curr_seq++;
            }
            
            longest_seq = max(curr_seq, longest_seq);
        }
        
        return longest_seq;
    }
};

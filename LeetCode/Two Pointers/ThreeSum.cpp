class Solution {
public: // two pointer approach
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            if(i > 0 && nums[i] == nums[i-1]) continue; // to avoid duplicate entries
            int tar = -nums[i];
            int j =i+1,k=n-1;
          
            while(j < k){
                int val = nums[j] + nums[k];
                if( val == tar){
                    res.push_back({nums[i],nums[j],nums[k]});
                    while(j <k && nums[j] == nums[j+1]) j++;  // to avoid duplicate entries
                    while(j <k && nums[k] == nums[k-1]) k--;  // to avoid duplicate entries
                    j++;
                    k--;
                }
                else if(val < tar)
                    j++;
                else
                    k--;
            }
        }
        return res;
    }
};

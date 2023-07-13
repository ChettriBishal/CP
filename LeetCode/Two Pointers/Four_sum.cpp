class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j> i+1 && nums[j] == nums[j-1]) continue;
                long tar = (long) target - nums[i]-nums[j];
                int l = j+1, r= n-1;
                while(l < r){
                   long curr = (long) nums[l] + nums[r];
                   if(curr == tar){
                      res.push_back({nums[i],nums[j],nums[l],nums[r]}); 
                       while(l < r && nums[l] == nums[l+1]) l++;
                       while(l < r && nums[r] == nums[r-1]) r--;
                       l++;
                       r--;
                   }
                    else if(curr < tar)
                        l++;
                    else 
                        r--;
                }
            }
        }
        return res;
    }
};

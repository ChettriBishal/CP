class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int diff = INT_MAX; // difference b/w target and sum
        
        int res = 0;
        
        for(int i=0;i < nums.size(); i++){
            int l = i+1;
            int r = nums.size() -1;
            
            while(l < r){

                int sum = nums[i] + nums[l] + nums[r];
                
                if(sum == target){
                    return sum;
                }
                else if(sum < target)
                    l++;
                else
                    r--;
                
                if(abs(sum - target) < diff){
                    diff = abs(sum - target);
                    res = sum;
                }
            }  
        }
        
        return res;
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        
        res[0] = findFirst(nums,target);
        
        if(res[0] == -1)
            return res;
        
        res[1] = findLast(nums,target);
        
        return res;
    }
    
    int findFirst(vector<int>& nums, int target){
        int lo = 0, hi = nums.size() -1;
        int res = -1;
        
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(nums[mid] < target){
                lo = mid + 1;
            }
            else if(nums[mid] > target){
                hi = mid - 1;
            }
            else{
                res = mid;
                hi = mid - 1; // try to search if it's present at more towards left 
            }
        }
        
        return res;
    }
    int findLast(vector<int>& nums, int target){
        int lo = 0, hi = nums.size() -1;
        int res = -1;
        
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(nums[mid] < target){
                lo = mid + 1;
            }
            else if(nums[mid] > target){
                hi = mid - 1;
            }
            else{
                res = mid;
                lo = mid + 1; // try to search if it's present at more towards right
            }
        }
        
        return res;
    }
};

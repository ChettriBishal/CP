class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int mine = INT_MAX, maxe = INT_MIN;
        bool sorted = true;
        for(int i =1;i<nums.size();i++){
            if(nums[i] < nums[i-1]) 
                sorted = false;
            if(! sorted)
                mine = min(mine, nums[i]);
        }
        sorted = true;
        for(int i= nums.size() - 2;i>= 0;i--){
            if(nums[i] > nums[i+1]) 
                sorted = false;
            if( !sorted)
                maxe = max(maxe,nums[i]);
        }
       
        int left , right;
        for(left =0;left < nums.size();left ++)
            if(nums[left] > mine) 
                break;
        for(right = nums.size()-1; right >=0 ; right --)
            if(nums[right] < maxe)
                break;
        if(left > right) // means array is sorted 
            return 0;
        return (right - left + 1);
    }
};

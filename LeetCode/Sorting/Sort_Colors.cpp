class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left, right, mid;
        left = mid = 0;
        right = nums.size()-1;
        while(mid <= right){
            if(nums[mid] == 0)
                swap(nums[mid++],nums[left++]);
            else if(nums[mid] == 1)
                mid++;
            else 
                swap(nums[mid],nums[right--]);
        }
      
    }
};

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), k, l;
      
        for(k = n-2;k >=0; k--){
            if(nums[k] < nums[k+1])
                break;
        }
        
        if(k < 0){ // already the greatest permutation 
            reverse(nums.begin(),nums.end());
            return;
        }
        
        for(l = n -1;l>k;l--){ // next greater element than nums[k]
            if(nums[l] > nums[k])
                break;
        }
      
        swap(nums[k], nums[l]);
      
        reverse(nums.begin()+k+1, nums.end());
    }
};

// example: (0, 1, 2, 5, 3, 3, 0)
// https://www.nayuki.io/page/next-lexicographical-permutation-algorithm

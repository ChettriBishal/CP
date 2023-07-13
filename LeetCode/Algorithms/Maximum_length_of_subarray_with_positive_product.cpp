class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        
        int res = getLen(nums); // ---->
        reverse(nums.begin(),nums.end()); // <---
        
        res = max(res, getLen(nums));
        
        return res;
        
    }
    
    int getLen(vector<int>&nums){
        int len = 0;
        
        int neg = 0; // count of negative numbers
        
        int s = -1; // starting point for subarray
        
        for(int i=0;i < nums.size();i++){
            
            neg += (nums[i] < 0);
            
            if(nums[i]){ // non zero number
                if(neg % 2 == 0){ // even count = +ve product
                    len = max(len, i - s);
                }
            }
            else{ // if current item is zero
                s = i;
                neg = 0;
            }        
        }
        
        return len;
    }
};

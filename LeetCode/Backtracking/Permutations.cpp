class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
        permuteRec(nums, 0);
        
        return result;
    }
    
    void permuteRec(vector<int>& nums,int l){
        
        if(l >= nums.size()){
            result.push_back(nums);
            return;
        }
        
        for(int i=l;i< nums.size();i++){
            swap(nums[i], nums[l]);
            permuteRec(nums,l+1);
            swap(nums[i], nums[l]); // backtracking
        }
        
    }
};

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        findCombination(0, candidates, curr, target);
        return res;
    }
    void findCombination(int start,vector<int>& arr, vector<int>& curr, int target){
        if(target <= 0){
            if(target == 0){
                res.push_back(curr);
            }
            return;
        }
        
        for(int i=start; i < arr.size();i++){
            // include 
            curr.push_back(arr[i]);
            findCombination(i, arr,curr,target - arr[i]);
            
            // exclude
            curr.pop_back();
        }
    }
};

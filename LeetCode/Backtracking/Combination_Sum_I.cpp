class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        findCombination(0,candidates,curr,target);
        
        return res;
    }
    void findCombination(int i, vector<int>& arr, vector<int> &curr, int target){
        if(target == 0){
            res.push_back(curr);
            return;
        }
        
        if(i >= arr.size() || target < 0){
            return;
        }
        
        // include the current item
        curr.push_back(arr[i]);
        findCombination(i,arr,curr, target - arr[i]);
        
        // exclude the current item
        curr.pop_back();
        findCombination(i+1,arr,curr, target);
    }
};

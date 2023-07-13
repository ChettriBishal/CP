class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        
        sort(candidates.begin(),candidates.end()); // group common elements together
        
        findCombination(0, candidates,curr,target);
        
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
            if(i > start && arr[i] == arr[i-1]) continue; // skip duplicate combinations
            // include 
            curr.push_back(arr[i]);
            findCombination(i + 1, arr,curr,target - arr[i]);

            // exclude
            curr.pop_back();
        }
    }
};

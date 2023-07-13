class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> not_grouped, ending_at;
        
        for(auto &x: nums)
            not_grouped[x]++;
      
        for(auto &x: nums){
            if(not_grouped[x] == 0)
                continue;
            
            not_grouped[x]--;
            
            if(ending_at[x-1] > 0){ // if there's a subsequence which ends at x-1
                ending_at[x-1]--;
                ending_at[x] ++; // now it ends at x 
            }
            else if(not_grouped[x+1] > 0 && not_grouped[x+2] > 0){
                not_grouped[x+1]--;
                not_grouped[x+2]--;
                ending_at[x+2]++; // ending at x + 2 
            }
            else
                return false;
        }
        return true;
    }
};

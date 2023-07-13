class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int,int> ind;
        int n = nums.size(); // size of the array
        
        ind[0] = -1;
        
        int tar = accumulate(nums.begin(),nums.end(),0) - x;
        
       // cout <<"tar = " << tar << endl;
        
        if(tar == 0) 
            return n;

        int res = INT_MIN;
        
        int run = 0; // running sum
        
        for(int i=0;i < n;i++){
            run += nums[i];
            
            if(ind.find(run - tar) != ind.end()){
                // cout << " i = " <<i << endl;
                // cout <<"ind[run - tar] " << ind[run - tar] <<endl;
                res = max(res,i - ind[run - tar]);
            }
            ind[run] = i;
            
        }
        if(res == INT_MIN) return -1;
        
        return n - res;
    }
};

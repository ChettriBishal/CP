class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue<int> q;
        
        int res = 0; // the number of operations needed
        
        vector<bool> visited(1001, false);
        q.push(start);
        
        while(!q.empty()){
            int size = q.size();
            
            while(size--){ // cause we have to go level by level 
                int val = q.front(); q.pop();

                if(val == goal) 
                    return res;
                
                if(val < 0 || val > 1000 || visited[val])
                    continue;

                visited[val] = true; // so that we don't compute again and again
              
                for(int i=0;i < nums.size();i++){ // the children produced by current val
                    int first = val + nums[i];
                    int second = val - nums[i];
                    int third = val ^ nums[i];
                    q.push(first);
                    q.push(second);
                    q.push(third);
                }
            }
            res++;
        }
        return -1;
    }
};

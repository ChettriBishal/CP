class Solution {
public:
    vector<int> matches;
    int target;
    bool makesquare(vector<int>& matchsticks) {
        this->matches = matchsticks;
        int sum = accumulate(begin(matches),end(matches),0);
        
        if(sum % 4)
            return false;
        
        target = sum / 4; // len of each side
        
        vector<int> sidesLength(4,0);
        
        sort(begin(matches), end(matches),greater<int>()); // reverse sort
        
        return dfs(sidesLength,0);      
    }
  
    bool dfs(vector<int>& sides, int ind){
        
        if(ind == matches.size()){
            return sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3];
        }
        
        for(int i=0;i < 4;i++){
            if(sides[i] + matches[ind] > target) continue;
            
            int j = i;
            
            while(--j >= 0){
                if(sides[j] == sides[i]) // if already encountered
                    break;
            }
            
            if(j != -1) continue;
            
            sides[i] += matches[ind]; // consider
            
            if(dfs(sides,ind+1))
                return true;
            
            sides[i] -= matches[ind]; // backtracking;
        }
        
        return false;
    }
};

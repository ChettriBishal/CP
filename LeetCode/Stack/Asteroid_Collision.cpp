class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s; // to store the asteroids encountered so far
      
        for(int &asteroid: asteroids){
            if(asteroid > 0)
                s.push(asteroid);
            else{ // explosion only when s.top() ----->    <------ asteroid
                while(!s.empty() && s.top() > 0 && s.top() < abs(asteroid)){
                    s.pop();
                }
                if(s.empty() || s.top() < 0)
                    s.push(asteroid);
                else if(s.top() == - asteroid) // when both are of same size 
                    s.pop();
            }
        }
        
        vector<int> ans(s.size());
        
        for(int i= s.size()-1; i>=0;i--){
                ans[i] = s.top(); s.pop();
        }
            
        return ans;
    }
};

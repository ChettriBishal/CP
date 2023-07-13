class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant, dire;
        int n = senate.size();
        
        for(int i=0;i < n;i++){
            if(senate[i] == 'R')
                radiant.push(i);
            else
                dire.push(i);
        }
        
        while(!radiant.empty() && !dire.empty()){
            int r_index , d_index;
            
            r_index = radiant.front(), d_index = dire.front();
            radiant.pop(); dire.pop();
            
            if(r_index < d_index) // if senator from radiant is present before 
                radiant.push(r_index + n);
            else
                dire.push(d_index + n);
        }
        return (radiant.size() > dire.size()) ? "Radiant" : "Dire";
    }
};
/*
the operation plus n means the corresponding senate can keep "alive" to the next round.
*/

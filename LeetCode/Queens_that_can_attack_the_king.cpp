class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        bool b[8][8] = {false};
        vector<vector<int>> result;
        for(auto& q: queens){
            b[q[0]][q[1]] = true;
        }
        for(int i= -1;i <=1;i++){ // to traverse all the eight directions and check the nearest queen 
            for(int j =-1;j <=1;j++){
                if(i == 0 && j == 0)
                    continue;
              
                int x = king[0] + i, y = king[1] + j;
              
                while(min(x,y) >=0 && max(x,y) < 8){
                    if(b[x][y]){
                        result.push_back({x,y});
                        break;
                    }
                    x += i;
                    y += j;
                }
            }
        }
        
        return result;
    }
};

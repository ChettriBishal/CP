class Solution {
public:
    class comp{
        public:
        int x,y;
        comp(pair<int,int> ok){
             x= ok.first;
             y = ok.second ;
        }
        bool operator() (vector<int>& a , vector<int>& b){
           int dist1 = abs(a[0] - x) + abs(a[1]- y);
           int dist2 = abs(b[0] - x) + abs(b[1] - y);
           return dist1 < dist2;
        }
        
    };
    
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> res;
        pair<int,int> pass(rCenter,cCenter);
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                res.push_back({i,j});
            }
        }
        sort(res.begin(),res.end(),comp(pass));
        return res;
            
    }
};

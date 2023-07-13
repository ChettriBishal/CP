class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        vector<unordered_map<string, int>> tables(501);
        set<string> foods;
        
        for(auto &v: orders){
            foods.insert(v[2]);
            tables[stoi(v[1])][v[2]]++;
        }
        
        vector<vector<string>> res;
        
        for(int t = 0; t <= 500; t++){
            if(t > 0 && tables[t].empty()) // if there is no order for table number 't'
                continue;
          
            res.push_back(vector<string>());
          
            res.back().push_back(t == 0 ? "Table" : to_string(t)); // res.back() --> cell in vector 
            
            for(auto it = foods.begin(); it != foods.end(); it++){
                res.back().push_back(t == 0 ? *it : to_string(tables[t][*it]));
            }
        }
        
        return res;
    }
};

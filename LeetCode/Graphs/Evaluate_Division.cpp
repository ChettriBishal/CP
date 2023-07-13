class Solution {
    unordered_map<string,vector<pair<string,double>>> graph;
    unordered_set<string> present; // those keys which are there in graph
    
    void buildGraph(vector<vector<string>>& vec, vector<double>& wt){
        for(int i=0;i < vec.size();i++){
            auto x = vec[i][0];
            auto y = vec[i][1];
            
            present.insert(x);
            present.insert(y);
            
            graph[x].push_back({y,wt[i]});
            if(wt[i]!= 0)
                graph[y].push_back({x,(double)1/wt[i]});
        }
    }
    
    pair<bool,double> search(string& a, string& b,unordered_set<string>&visited,double val){
        if(visited.count(a) == 0){
            visited.insert(a);
            
            for(auto &nbr: graph[a]){
                double temp = val * nbr.second;
                if(nbr.first == b){
                    return {true,temp};
                }
                auto res = search(nbr.first,b,visited,temp);
                if(res.first)
                    return res;
            }
        }
        
        return {false,-1.0};
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        buildGraph(equations,values);
        
        vector<double> result;
        
        for(auto& q: queries){
            
            unordered_set<string> visited;
            if(present.find(q[1]) == present.end() || present.find(q[0]) == present.end())
                result.push_back(-1.0);
            else if(q[0] == q[1])
                result.push_back(1.0);
            else
            {
                auto p = search(q[0], q[1], visited,1.0);
                result.push_back(p.second);
            }
        }
        
        return result;
    }
    
};

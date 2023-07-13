class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<int> answer; // to store the intermediate results
    vector<int> quiet;
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        this-> quiet = quiet;
        
        answer.resize(n,-1);
        
        for(auto &vec: richer){
            graph[vec[1]].push_back(vec[0]);
        }
        
        for(int node = 0; node < n; node++)
            dfs(node);
        
        return answer;
    }
    int dfs(int node){
        if(answer[node] != -1) // memoization 
            return answer[node];
        
        answer[node] = node;
        
        for(auto& nbr: graph[node]){
            int cand = dfs(nbr);
            if(quiet[cand] < quiet[answer[node]])
                answer[node] = cand;
        }
        return answer[node];
    }
};

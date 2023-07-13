class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        vector<bool> visited(n+1, false);
        
        vector<vector<int>> graph(n+1);
        
        for(auto &vec: edges){
            fill(visited.begin(), visited.end(), false);
            graph[vec[0]].push_back(vec[1]);
            graph[vec[1]].push_back(vec[0]);
            
            if(dfs(vec[0], visited,graph)) // if the last edge added resulted in cycle
                return vec;
        }
        
        return {};
    }
    
    bool dfs(int node, vector<bool> &visited, vector<vector<int>> & graph, int parent=-1){
        if(visited[node])
            return true;
        
        visited[node] = true;
        
        for(auto &nbr: graph[node]){
            if(nbr != parent && dfs(nbr, visited, graph, node))
                return true;
        }
        
        return false;
    }
};

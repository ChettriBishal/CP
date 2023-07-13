class Solution {
    vector<vector<int>> result;
    
    void dfs(vector<vector<int>>& graph,vector<int>& path,int node){
        
        path.push_back(node);
        if(node == graph.size()-1){
            result.push_back(path);
        }
        else 
            for(auto& nbr: graph[node]){
                dfs(graph,path,nbr);
            }
        path.pop_back();
    }
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        
        dfs(graph,path,0);
        
        return result;
    }
};

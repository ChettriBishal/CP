class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, 0); // 0 --> not colored
        for(int i=0;i < n; i++){
            if(colors[i] == 0 && ! dfs(graph, colors,i, 1))
                return false;
        }
        return true;
    }
    
    bool dfs(vector<vector<int>> & graph, vector<int>& colors, int node, int color)
    {
        if(colors[node] != 0){ // if already visited before
            return colors[node] == color;
        }
        
        colors[node] = color;
        for(auto &nbr: graph[node]){
            if(dfs(graph, colors, nbr, -color) == false)
                return false;
        }
        
        return true;
        
    }
};

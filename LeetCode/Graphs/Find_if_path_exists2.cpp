class Solution {
public:
    unordered_map<int,list<int>> l;
    unordered_map<int,bool> visited;
    void addedge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    bool dfs_util(int src,const int& end ){
        visited[src] = true;
        if(src == end)
            return true;
        for(auto &k: l[src]){
            if(!visited[k]){
               bool yes =  dfs_util(k, end);
                if(yes)
                    return yes;
            }
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        for(auto &edge: edges){
            addedge(edge[0],edge[1]);
        }
        
        return dfs_util(start,end);
       
    }
};

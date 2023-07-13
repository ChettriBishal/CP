class Solution {
public:
    unordered_map<int,list<int>> l;
    void addedge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        for(auto &edge: edges){
            addedge(edge[0],edge[1]);
        }
        queue<int> q;
        unordered_map<int,bool> visited;
        q.push(start);
        visited[start] = true;
        while(!q.empty()){
            int node = q.front();
            if(node == end)
                return true;
            q.pop();
            for(auto &k: l[node]){
                if(!visited[k]){
                    q.push(k);
                    visited[k] = true;
                }
            }
        }
        return false;
    }
};

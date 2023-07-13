class Solution {
private:
    bool isCyclic(int node,vector<vector<int>> &adj, vector<int> & visited){
        if(visited[node] == 1) // present in the current path
            return true;
        
        visited[node] = 1; // processing
        
        for(auto &nbr: adj[node]){
            if(visited[nbr] != 2 && isCyclic(nbr,adj,visited))
                return true;
        }
        
        visited[node] = 2; // processed --> not in the current path
        
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& preq) {
        vector<vector<int>> adj(numCourses); // adjacency list
        
        for(int i=0;i < preq.size();i++)
            adj[preq[i][0]].push_back(preq[i][1]);
        
        vector<int> visited(numCourses, 0);
        
        for(int i=0;i < numCourses;i++){
            if(visited[i] == 0){
                if(isCyclic(i, adj, visited))
                    return false;
            }
        }
        return true;
    }
};
/*
0 ---> Not visited
1 ---> In current path considered
2 ---> Not in current path
*/

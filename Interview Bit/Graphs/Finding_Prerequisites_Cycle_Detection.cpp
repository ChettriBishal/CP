
bool cycle(int node, unordered_map<int,vector<int>>& graph,vector<int>&visited){
    if(visited[node] == 1) // if present in the current path
        return true;
    visited[node] = 1; // in current path 
  
    for(auto &nbr: graph[node]){
        if(visited[nbr] == 1) // if already present in the current path 
            return true;
        else if(visited[nbr] == 0){
            bool cyclic = cycle(nbr,graph,visited);
            if(cyclic)
                return true;
        }
    }
  
    visited[node] = 2; 
    return false;
}

int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    unordered_map<int,vector<int>> graph;
    for(int i=0;i < B.size();i++){
        graph[B[i]].push_back(C[i]);
    }

    vector<int> visited(A+1, 0);
    for(int i=1; i <=A;i++){
        if(!visited[i] && cycle(i, graph,visited)){ // cycle detected
            return false;
        }
    }
  
    return true;
}

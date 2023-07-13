bool cycle_helper(unordered_map<int,vector<int>>& graph,int node, vector<bool>& visited,int parent){
    visited[node] = true;
    for(auto &nbr: graph[node]){
        if(!visited[nbr]){
            bool cycle_there = cycle_helper(graph,nbr,visited,node);
            if(cycle_there)
                return true;
        }
        else if(parent != nbr) // if visited but not equal to parent 
            return true;
    }
    return false;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<bool> visited(A+1,false);
    unordered_map<int,vector<int>> graph;
    for(auto &vec: B){
        graph[vec[0]].push_back(vec[1]);
        graph[vec[1]].push_back(vec[0]);
    }
    for(int i=1;i <= A;i++){ // graph may have multiple components so iteration is necessary
        if(!visited[i] && cycle_helper(graph,i,visited,-1))
            return true;
    }
    return false;
}

int dfs(vector<vector<int>>&graph,vector<int>&A,vector<bool>&visited,int node, int C){

    if(C < 0){
        return 0;
    }

    if(graph[node].size() == 1){ // means we are at the leaf node
        return 1;
    }

    visited[node] = true;
    int ok = 0;
    for(auto &nbr: graph[node]){
        if(!visited[nbr]){
            ok += dfs(graph,A,visited,nbr,C - A[nbr]);
        }
    }
    visited[node] = false;
    return ok;
}



int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) {
    int n = A.size();

    vector<vector<int>> graph(n);

    for(auto &vec: B){
        graph[vec[0]-1].push_back(vec[1]-1);
        graph[vec[1]-1].push_back(vec[0]-1);
    }

    vector<bool> visited(n,false);
    
    int res = dfs(graph,A,visited,0,C-A[0]);

    return res;
}

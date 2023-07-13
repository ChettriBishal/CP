int Solution::solve(int A, vector<vector<int> > &B) {
    unordered_map<int,vector<int>>graph;

    for(auto &v: B){
        graph[v[0]].push_back(v[1]);
    }

    vector<int> dist(A+1,-1);
    queue<int> q;
    dist[1] = 0; // distance of source node is zero
    q.push(1);
    
    while(!q.empty()){
        int node = q.front(); q.pop();
        for(auto &nbr: graph[node]){
            if(dist[nbr] == -1){
                dist[nbr] = dist[node] + 1;
                q.push(nbr);
            }
        }
    }

    if(dist[A] == -1)
            return 0;
    return 1;
}

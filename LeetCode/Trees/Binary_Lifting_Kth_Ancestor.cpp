class TreeAncestor {
    vector<vector<int>> par;
    int LOG;
public:
    TreeAncestor(int n, vector<int>& parent) {
        LOG = 0;
        while((1<<LOG) <=n) LOG++;
        
        par = vector<vector<int>>(n,vector<int>(LOG));
        
        for(int v =0;v <n;v++)
            par[v][0] = parent[v];
        
        // par[v][j] --> 2^jth ancestor of V
        for(int j=1;j <LOG;j++){
            for(int v =0; v < n;v++){
                if(par[v][j-1] == -1)
                    par[v][j] = -1;
                else
                    par[v][j] = par[par[v][j-1]][j-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0;i < LOG;i++){
            if((1 << i) & k){
                node = par[node][i];
                if(node == -1)
                    return -1;
            }
        }
        return node;
    }
};

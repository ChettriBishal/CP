int u_find(int x,vector<int>& parent){
    if(parent[x] == -1)
        return x;
    return parent[x] = u_find(parent[x],parent);
}

int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    vector<int> parent(A+1,-1);
    
    for(int i=0;i < B.size();i++){
        if(parent[B[i]] == C[i])
            continue;
        int s1 = u_find(B[i], parent);
        int s2 = u_find(C[i], parent);
        if(s1 == s2)   // cycle was found 
            return 0;
        else
            parent[s1] = s2;   
    }
    
    return 1;
}

int u_find(int x, vector<int>& parent){ // DSU find
    if(parent[x] == -1)
        return x;
    return parent[x] = u_find(parent[x], parent);
}

bool union_set(int x,int y,vector<int>& parent,vector<int>& rank){ // Union
    int s1 = u_find(x,parent);
    int s2 = u_find(y,parent);
    if(s1 != s2){
        if(rank[s1] < rank[s2]){
            parent[s1] = s2;
            rank[s2] += rank[s1];
        }
        else{
            parent[s2] = s1;
            rank[s1] += rank[s2];
        }
        return true; // if we are able to perform union return true
    }
    else
        return false; // union wasn't performed 
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> visited(A+1,false);
    vector<int> parent(A+1,-1);
    vector<int> rank(A+1,1);
  
    for(auto&vec: B){
        if(!union_set(vec[0],vec[1],parent,rank))
            return true;
    }
  
    return false;
}

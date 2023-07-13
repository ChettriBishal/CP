class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    struct edge{
        int x,y, w;  
    };
    
    int find(int x){
        if(parent[x] == -1)
            return x;
        return parent[x] = find(parent[x]);
    }
    
    bool union_set(int x, int y){ // returns true if we were able to union two sets
        int s1 = find(x);
        int s2 = find(y);
        if(s1 != s2){
            if(rank[s1] < rank[s2]){
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else{
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
            return true;
        }
        else
            return false;
    }
    
    int getdist(vector<int>& p1, vector<int>& p2){
        int dist = abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
        return dist;
    }
    static bool comp(edge& a, edge& b){
        return a.w < b.w;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) { // kruskal + DSU
        vector<edge> edgelist;
        
        int V = points.size(); // no of vertices
        
        parent.resize(V,-1), rank.resize(V,1);
        
        for(int i=0;i < V;i++){
            for(int j= i+1;j < V;j++){
                int cost = getdist(points[i], points[j]);
                edgelist.push_back({i,j,cost});
            }
        }
       
        sort(edgelist.begin(),edgelist.end(),comp); // sorting on the basis of weight
       
        int minCost = 0;
        
        for(auto &edge: edgelist){
            int x = edge.x;
            int y = edge.y;
            int w = edge.w; 
            if(union_set(x,y)){
                minCost += w;
            }
        }
        
        return minCost;
    }
};

class Solution {
    vector<int> rank, parent;
    int m; // size of the grid
    
    int find(int x){
        if(parent[x] == -1)
            return x;
        return parent[x] = find(parent[x]); // path compression
    }
    
    bool union_set(int x, int y){ // returns true if we are able to union 
        int px = find(x);
        int py = find(y);
        if(px != py){
            if(rank[px] < rank[py]){
                parent[px] = py;
                rank[py] += rank[px];
            }
            else{
                parent[py] = px;
                rank[px] += rank[py];
            }
            return true;
        }
        else // means there is cycle 
            return false;
    }
    
public:
    int regionsBySlashes(vector<string>& grid) {
        m = grid.size();
        
        int dots = m+1;
        
        int maxn = dots * dots;
        
        rank.resize(maxn,1); parent.resize(maxn,-1);
        
        int regions = 1; // initally the whole box is the region
        
        // connect the boundary 
        for(int i=0;i < dots;i++){
            for(int j=0;j < dots;j++){
                if(i == 0 || j == 0 || i == dots-1 || j == dots-1){
                    int cellno = i* dots + j;
                    union_set(0, cellno);
                }
            }
        }
        
        for(int i=0;i < m;i++){
            for(int j=0;j < m;j++){
                int x, y;
                if(grid[i][j] == '/'){
                    x = (i+1)* dots + j; // (i+1,j)
                    y = i * dots + (j+1); // (i,j+1)
                    if(!union_set(x,y))
                        regions++;
                }
                else if(grid[i][j] == '\\'){
                    x = i * dots + j; //(i,j)
                    y = (i+1) * dots + (j+1); //(i+1,j+1)
                    if(!union_set(x,y))
                        regions++;
                }
            }
        }
        
        return regions;
    }
};

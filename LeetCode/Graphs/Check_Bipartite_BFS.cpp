class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> colors(n, 0);
        
        for(int i=0;i < n;i++){
            
            if(colors[i] == 0){
                queue<int> q;
                q.push(i);
                colors[i] = 1;
                
                while(! q.empty()){
                    int node = q.front();
                    q.pop();
                    
                    for(auto &nbr: graph[node]){
                        if(colors[nbr] == 0){
                            colors[nbr] = - colors[node];
                            q.push(nbr);
                        }
                        else if(colors[nbr] == colors[node])
                            return false;
                    }
                } 
            }
        }
        return true;
    }
};

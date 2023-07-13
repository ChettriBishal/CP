class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& preq) {
        vector<vector<int>> graph(numCourses);
        vector<int> result;
        vector<int> indegree(numCourses,0);
        
        for(auto &vec: preq){ // create adjacency list 
            graph[vec[1]].push_back(vec[0]);
        }
        
        for(int i=0;i < numCourses;i++){
            for(auto &nbr: graph[i])
                indegree[nbr]++;
        }
        
        queue<int> q;
        
        for(int i=0;i < numCourses;i++)
            if(indegree[i] == 0)
                q.push(i);
        
        while(!q.empty()){
            int node = q.front(); q.pop();
            
            result.push_back(node);
            
            for(auto &nbr: graph[node]){
                if(--indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
        
        if(result.size() != numCourses) // means we have back edge somewhere 
            return {};
        
        return result;
        
    }
};
/*
Here
[a,b] implies b ---> a; after b comes a
Thus indegree of b is 0; while a is 1
*/
